///////////////////////////////////////////////
///
/// deal with the input and output
///
///////////////////////////////////////////////

#pragma once
#include "type.hpp"
#include "trie.hpp"
enum IOErrorType{
    IO_OK = 0,
    ILLEGAL_FILE
};
int fileToStr(const char* file, char** raw);
int strToFile(char* file, char* raw, int len);
Word* getOneWord(const char** raw,Trie& tree);
WordList* getWords(const char* raw);
char* to_str(std::list<Word*>& words);
void charCopy(const char* src, char* dst, int len);

