
#include "interface.hpp"
#include "algorithm.hpp"
#include "type.hpp"
#include "IO.hpp"
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char check(char c){
	if(c >= 'A' && c <= 'Z'){
		return c - 'A' + 'a';
	}
	else if(!(c >= 'a' && c <= 'z') && c != 0){
		printf("Illegal head or tail character.\n");
		exit(0);
	}
	else
		return c;
}

int gen_chain_word(char* raw, int len, char* result[], char head, char tail){
	auto wordlist = getWords(raw);
	char low_head = check(head), low_tail = check(tail);
	list<list<Word*> >results;
	long result_num;
	result_num = MostWords(wordlist, low_head, low_tail, results);
	if(result_num <= 0) return result_num;
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
	auto wordlist = getWords(raw);
	char low_head = check(head), low_tail = check(tail);
	list<list<Word*> >results;
	long result_num;
	result_num = MostCharacters(wordlist, low_head, low_tail, results);
	if(result_num <= 0) return result_num;
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
    if(mode == 0) return first_result.size();
    else if(mode == 1) return result_num;
    else{
        printf("Illegal mode.\n");
        return -1;
    }
}


int gen_chain_number(char* raw, int len, std::list<std::list<char*> > &result, char head, char tail, int number){
	if(number <= 1){
        printf("Number must be greater than 1.\n");
        return -1;
    }
    auto wordlist = getWords(raw);
	char low_head = check(head), low_tail = check(tail);
	list<list<Word*> >results;
	long result_num;
	result_num = RequiredNumber(wordlist, low_head, low_tail, number, results);
	if(result_num <= 0) return result_num;
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
