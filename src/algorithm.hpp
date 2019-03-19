

#ifndef __ALGORITHM_HPP__
#define __ALGORITHM_HPP__
//error code
#define NOTENGLISHLETTER -1
#define NOTFOUND -2
#define NINF -1
#include "type.hpp"
#include <string.h>


//This function can find a word chain with most words
//@wordlist: input wordlist
//@head: the required head character of the first word in the chain, it must be 0 if there is no such a requirement
//@tail: the required tail character of the last word in the chain, it must be 0 if there is no such a requirement
//@result: the word chain with most words, it's a return value
//@return value of this function: the number of words in the result chain
long MostWords(struct WordList *wordlist, char head, char tail, std::list<std::list<Word*> > &result);

//This function can find a word chain with most characters
//@wordlist: input wordlist
//@head: the required head character of the first word in the chain, it must be 0 if there is no such a requirement
//@tail: the required tail character of the last word in the chain, it must be 0 if there is no such a requirement
//@result: the word chain with most characters, it's a return value
//@return value of this function: the number of words in the result chain
long MostCharacters(struct WordList *wordlist, char head, char tail, std::list<std::list<Word*> > &result);

//This function can find a word chain with required word number
//@wordlist: input wordlist
//@head: the required head character of the first word in the chain, it must be 0 if there is no such a requirement
//@tail: the required tail character of the last word in the chain, it must be 0 if there is no such a requirement
//@result: the list of any word chain meets the requirement, it's a return value
//@return value of this function: the number of word chains
long RequiredNumber(struct WordList *wordlist, char head, char tail, long number, std::list<std::list<Word*> > &result);
#endif