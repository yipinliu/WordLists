#include<list>

#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__
#include "IO.hpp"
#include "algorithm.hpp"

//This function aims to get the word chains with most words
//@raw:input word chain
//@len: the length of input chain
//@result: the word chain with most words
//@head: the head character which is required in the result chain, it must be 0 if there is no such a requirement
//@tail: the tail character which is required in the result chain, it must be 0 if there is no such a requirement
int gen_chain_word(char* raw, int len, char* result[], char head, char tail);

//This function aims to get the word chains with characters
//@words:input word chain
//@len: the length of input chain
//@result: the word chain with most characters
//@head: the head character which is required in the result chain, it must be 0 if there is no such a requirement
//@tail: the tail character which is required in the result chain, it must be 0 if there is no such a requirement
int gen_chain_char(char* raw, int len, char* result[], char head, char tail, char mode);

//This function aims to get the word chains with specific words
//@words:input word chain
//@len: the length of input chain
//@result: the word chain with specific words(all chains will return)
//@head: the head character which is required in the result chain, it must be 0 if there is no such a requirement
//@tail: the tail character which is required in the result chain, it must be 0 if there is no such a requirement
//@number: the number of words required in the result chain
int gen_chain_number(char* raw, int len, std::list<std::list<char*> > &result, char head, char tail, int number);


#endif