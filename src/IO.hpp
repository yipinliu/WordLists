///////////////////////////////////////////////
///
/// deal with the input and output
///
///////////////////////////////////////////////

#ifndef __IO_HPP__
#define __IO_HPP__
#include "type.hpp"
enum IOErrorType{
    IO_OK = 0,
    ILLEGAL_FILE
};
IOErrorType fileToStr(char* file, char** raw);
IOErrorType strToFile(char* file, char* raw, int len);
Word* getOneWord(char** raw);
WordList* getWords(char* raw);
char* to_str(std::list<Word*>& words,bool needNewLine);

#endif