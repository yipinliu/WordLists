

#define WHITE 0
#define GREY 1
#define BLACk 2
//error code
#define NOTENGLISHLETTER -1
#define NOTFOUND -2



//This function can find a word chain with most words
//@wordlist: input wordlist
//@head: the required head character of the first word in the chain, it must be 0 if there is no such a requirement
//@tail: the required tail character of the last word in the chain, it must be 0 if there is no such a requirement
//@result: the word chain with most words, it's a return value
//@return value of this function: the number of words in the result chain
long MostWords(struct WordList *wordlist, char head, char tail, list<list<Word*>> &result);

//This function can find a word chain with most characters
//@wordlist: input wordlist
//@head: the required head character of the first word in the chain, it must be 0 if there is no such a requirement
//@tail: the required tail character of the last word in the chain, it must be 0 if there is no such a requirement
//@result: the word chain with most characters, it's a return value
//@return value of this function: the number of words in the result chain
long MostCharacters(struct WordList *wordlist, char head, char tail, list<list<Word*>> &result);

//This function can find a word chain with required word number
//@wordlist: input wordlist
//@head: the required head character of the first word in the chain, it must be 0 if there is no such a requirement
//@tail: the required tail character of the last word in the chain, it must be 0 if there is no such a requirement
//@result: the list of any word chain meets the requirement, it's a return value
//@return value of this function: the number of word chains
long RequiredNumber(struct WordList *wordlist, char head, char tail, long number, list<list<Word*>> &result);