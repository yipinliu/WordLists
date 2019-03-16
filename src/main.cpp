#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <string>

#include "IO.hpp"
#include "algorithm.hpp"
using namespace std;

#define ESCAPE(ptr) \
    do{\
        while(*ptr == ' ') ptr++;\
    }while(0)
#define ISWORDCHAR(c) (c >= 'a'&&c <= 'z' || c>='A'&&c<='Z')
#define CHECKCHAR(c)\
    do{\
        if(c>= 'A'&&c<='Z') c = c - 'A' + 'a';\
        else if(c < 'a' || c > 'z'){\
            return ILLEGAL_CHAR;\
        }\
    }while(0)
#define GETCHAR(c) \
    do{\
        if(i==argc-1) return MISSING_ARGUMENT;\
        i++;\
        c = *argv[i];\
        CHECKCHAR(c);\
    }while(0)
#if 1
#define PRINTF(str) printf(str)
#define OUT(str) cout<<str<<endl
#else 
#define PRINTF(str) 
#define OUT(str) 
#endif
static char h = '\0';
static char t = '\0';
static int n = -1;
static bool isw = true;
static bool has_nwc = false;
static bool is_file = false;
static char* file = nullptr;
static char* raw = nullptr;


enum ErrorType{
    PARSE_OK = 0,
    MISSING_WCN,
    MISSING_ARGUMENT,
    INVALID_ARGUMENT,
    MULTIPE_SAME,
    NEGATIVE_NUMBER,
    ILLEGAL_CHAR,
    NWC_CONFLICT,
    NO_INPUT,
    MULTIPE_INPUT
};
string err_msg[] = {
    "please wait...",
    "Error: you must assign a searching type(-w/-c/-n)!",
    "Error: missing argument!",
    "Error: invalid argument!",
    "Error: can't define multipe argument!",
    "Error: the number can't be negative!",
    "Error: illegal character!",
    "Error: you must choose only one searching type!",
    "Error: you must input some words!",
    "Error: file and word list are alternative"
};
ErrorType parseCommandLine(int argc, char** argv);

int main(int argc,char *argv[])
{
    ErrorType state = parseCommandLine(argc,argv);
    cout<<err_msg[state]<<endl;
    if(state != PARSE_OK) return 0;
    if(file){
        int no = fileToStr(file,&raw);
        if(raw == nullptr){
            printf("Error: invalid file");
            return 0;
        }
    }
    auto wordList = getWords(raw);
    list<list<Word*> >results;
    long result_num = 0;
    if(n!=-1){
        result_num = RequiredNumber(wordList,h,t,n,results);
    }
    else if(isw){
        result_num = MostWords(wordList,h,t,results);
    }
    else{
        result_num = MostCharacters(wordList,h,t,results);
    }
    cout<<result_num<<endl;
    for(auto& e: results){
        cout<<to_str(e,(n!=-1 || isw))<<endl;
    }
    delete[] wordList;
    return 0;
}
ErrorType checkInput(){
    if(!has_nwc) return MISSING_WCN;
    if(!(file||raw)) return NO_INPUT;
    if(file&&raw) return MULTIPE_INPUT;
    return PARSE_OK;
}
ErrorType parseCommandLine(int argc,char**argv){
    if(argc == 1) return MISSING_ARGUMENT;
    for(int i = 1; i < argc; i++){
        char *p = argv[i];
        ESCAPE(p);
        if(*p != '-'&&!ISWORDCHAR(*p)) return INVALID_ARGUMENT;
        if(*p != '-'){
            if(raw != nullptr) return MULTIPE_SAME;
            raw = p;
            continue;
        }
        p++;
        if(*p=='w'){
            if(has_nwc) return NWC_CONFLICT;
            isw = true;
            has_nwc = true;
        }
        else if(*p == 'c'){
            if(has_nwc) return NWC_CONFLICT;
            isw = false;
            has_nwc = true;
        }
        else if(*p == 'n'){
            if(i == argc -1) return MISSING_ARGUMENT;
            if(has_nwc) return NWC_CONFLICT;
            has_nwc = true;
            i++;
            n = atoi(argv[i]);
            if(n<0) return NEGATIVE_NUMBER;
        }
        else if(*p == 'h'){
            GETCHAR(h);
        }
        else if(*p == 't'){
            GETCHAR(t);
        }
        else if(*p == 'f'){
            if(i == argc -1) return MISSING_ARGUMENT;
            i++;
            p = argv[i];
            ESCAPE(p);
            file = p;
        } 
    }
    return checkInput();
}