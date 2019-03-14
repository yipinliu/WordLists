#include "IO.hpp"
#include <stdio.h>
#include <string.h>
using namespace std;
#define IS_ELEMENT(c) ((c)>='a'&&(c)<='z'||(c)>='A'&&(c)<='Z')
#define IS_DELIMITER(c) (!IS_ELEMENT(c))
#define ESCAPE_DELIMITER(ptr)\
    do{\
        while(*ptr != '\0'&&IS_DELIMITER(*ptr)) ptr++;\
    }while(0)

IOErrorType fileToStr(char* fileName, char** raw){
    FILE *file = fopen(fileName,"rb");
    if(!file) return ILLEGAL_FILE;
    fseek(file,0,SEEK_END);
    int len = ftell(file);
    fseek(file,0,SEEK_SET);
    char* p = (char*)(malloc(sizeof(len+1)));
    fread(p,sizeof(char),len,file);
    p[len] = '\0';
    *raw = p;
    fclose(file);
    return IO_OK;
}
IOErrorType strToFile(char* fileName, char* raw, int len){
    FILE* file = fopen(fileName, "wb");
    if(!file) return ILLEGAL_FILE;
    fwrite(raw,sizeof(char),len,file);
    fclose(file);
    return IO_OK;
    
}
void charCopy(char* src, char* dst, int len){
    for(int i = 0; i< len; i++){
        if(src[i]>='A'&&src[i]<='Z')
            dst[i] = src[i] - 'A' + 'a';
        else
        {
            dst[i] = src[i];
        }
        
    }
}
list<ListNode>::iterator getPosition(list<ListNode>& ls,ListNode& ln){
    auto end = ls.end();
    for(auto iter = ls.begin(); iter != end;iter++){
        if(iter->w->len < ln.w->len) return iter;
    }
    return end;
}
Word* getOneWord(char** raw){
    char* p = *raw;
    ESCAPE_DELIMITER(p);
    if(*p=='\0'){
        *raw = p;
        return nullptr;
    }
    int i = 0;
    while(p[i] != '\0'&&IS_ELEMENT(p[i])) i++;
    Word* word = new Word;
    word->raw = new char[i];
    word->len = i;
    charCopy(p,word->raw,i);
    word->first = word->raw[0];
    word->last = word->raw[i-1];
    *raw = &p[i];
    return word;

}
WordList* getWords(char* raw){
    WordList* wordlist = new WordList[26];
    char*p = raw;
    while(*p != '\0'){
        auto word = getOneWord(&p);
        if(word == nullptr) continue;
        ListNode hnode, tnode;
        hnode.w = word;
        tnode.w = word;
        auto& ls = wordlist[word->first-'a'].hlist;
        ls.insert(getPosition(ls,hnode),hnode);
        auto& tls = wordlist[word->last - 'a'].tlist;
        tls.insert(getPosition(tls,tnode),tnode);
    }
    return wordlist;
}
int getLen(list<Word*> &words){
    auto end = words.end();
    int sum = 0;
    for(auto e: words){
        sum += e->len;
    }
    return sum;
}
char* to_str(list<Word*> &words,bool needNewLine){
    int len = getLen(words) + 1 + (words.size()-1)*(int)needNewLine;
    char* result = new char[len];
    char* p = result;
    auto end = words.end();
    for(auto iter = words.begin(); iter != end; iter++){
        strncpy(p,(*iter)->raw,(*iter)->len);
        p = &p[(*iter)->len];
        if(needNewLine){
            *p = '\n';
            p++;
        }
    }
    *p = '\0';
    return result;
}