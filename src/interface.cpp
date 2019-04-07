
#include "interface.hpp"
#include "algorithm.hpp"
#include "type.hpp"
#include "IO.hpp"
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void error_handler(int err){
    switch(err){
        case HEADORTAIL_ILLEGAL:
            printf("ERROR:The head or tail character is illegal!\n");
            break;
        case NUMBER_LESSTHANONE:
            printf("ERROR:The specified number must be larger than 1.\n");
            break;
        case NOTFOUNDD:
            printf("ERROR:Unable to find the required word chain.\n");
            break;
        case LEN_LESSTHANZERO:
            printf("ERROR:Len must be larger than 0.\n");
            break;
        case NUMBER_LARGERTHANLEN:
            printf("ERROR:Number must be less than len.\n");
            break;
        case ILLEGAL_MODE:
            printf("ERROR:Illegal mode.\n");
            break;
        case UNKNOWNERROR:
            printf("ERROR:Unknown error happened.\n");
            break;
        default:
            return;
    }
    exit(0);

}


char check_char(char c){
    try
    {
        if(c >= 'A' && c <= 'Z'){
            return c - 'A' + 'a';
        }
        else if(!(c >= 'a' && c <= 'z') && c != 0){
            throw HEADORTAIL_ILLEGAL;
        }
        else
            return c;
    }
    catch(int err)
    {
        error_handler(err);
    }
	return c;
}

void check_number(int number, int len){
    try
    {
        if(number <= 1)
            throw NUMBER_LESSTHANONE;
        if(number > len)
            throw NUMBER_LARGERTHANLEN;
    }
    catch(int err)
    {
        error_handler(err);
    }
}

void check_returnvalue(int returnvalue){
    try
    {
        if(returnvalue == -1)
            throw HEADORTAIL_ILLEGAL;
        if(returnvalue == -2)
            throw NOTFOUNDD;
        if(returnvalue == 0)
            throw UNKNOWNERROR;
    }
    catch(int err)
    {
        error_handler(err);
    }
}

void check_len(int len){
    try
    {
        if(len <= 0)
            throw LEN_LESSTHANZERO;
    }
    catch(int err)
    {
        error_handler(err);
    }
}

int check_mode(int mode, int mode_0, int mode_1){
    try
    {
        if(mode == 0)
            return mode_0;
        else if(mode == 1)
            return mode_1;
        else
            throw ILLEGAL_MODE;
    }
    catch(int err)
    {
        error_handler(err);
    }
}

int gen_chain_word(char* raw, int len, char* result[], char head, char tail){
	char low_head = check_char(head), low_tail = check_char(tail);
    check_len(len);
    auto wordlist = getWords(raw);
	list<list<Word*> >results;
	long result_num;
	result_num = MostWords(wordlist, low_head, low_tail, results);
	check_returnvalue(result_num);
    auto first_result = results.front();
    long chain_length = results.size();
    int k = 0;
    for(auto iter = first_result.begin(); iter != first_result.end(); iter++, k++){
    	int word_length = 0;
    	while((*iter)->raw[word_length] != '\0') word_length++;
    	char *result_word = (char *)malloc((word_length+1) * sizeof(char));
    	charCopy((*iter)->raw, result_word, word_length);
    	result_word[word_length] = '\0';
    	result[k] = result_word;
    }
    return result_num;
}


int gen_chain_char(char* raw, int len, char* result[], char head, char tail, char mode){
	char low_head = check_char(head), low_tail = check_char(tail);
    check_len(len);
    auto wordlist = getWords(raw);
	list<list<Word*> >results;
	long result_num;
	result_num = MostCharacters(wordlist, low_head, low_tail, results);
	check_returnvalue(result_num);
    auto first_result = results.front();
    long chain_length = results.size();
    int k = 0;
    for(auto iter = first_result.begin(); iter != first_result.end(); iter++, k++){
    	int word_length = 0;
    	while((*iter)->raw[word_length] != '\0') word_length++;
    	char *result_word = (char *)malloc((word_length+1) * sizeof(char));
    	charCopy((*iter)->raw, result_word, word_length);
    	result_word[word_length] = '\0';
    	result[k] = result_word;
    }
    return check_mode(mode, first_result.size(), result_num);
}


int gen_chain_number(char* raw, int len, std::list<std::list<char*> > &result, char head, char tail, int number){
    char low_head = check_char(head), low_tail = check_char(tail);
    check_len(len);
    check_number(number, len);
    auto wordlist = getWords(raw);
	list<list<Word*> >results;
	long result_num;
	result_num = RequiredNumber(wordlist, low_head, low_tail, number, results);
	check_returnvalue(result_num);
    for(auto iterr = results.begin(); iterr != results.end(); iterr++){
    	list<char*> chain;
    for(auto iter = (*iterr).begin(); iter != (*iterr).end(); iter++){
    	int word_length = 0;
    	while((*iter)->raw[word_length] != '\0') word_length++;
    	char *result_word = (char *)malloc((word_length+1) * sizeof(char));
    	charCopy((*iter)->raw, result_word, word_length);
    	result_word[word_length] = '\0';
    	chain.push_back(result_word);
    }
    	result.push_back(chain);
	}
    return result_num;
}
