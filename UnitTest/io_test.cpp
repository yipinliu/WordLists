#include "gtest/gtest.h"
#include "IO.hpp"
#include <string>
#include <cstring>
using namespace std;

TEST(fileToStr, invalid_file){
    char* p = nullptr;
    string file = "no_exists.txt";
    string file2 = "no_exists2.txt";
    EXPECT_EQ(1, fileToStr(&file[0],&p));
    EXPECT_EQ(nullptr, p);
    EXPECT_EQ(1, fileToStr(&file[0],&p));
    EXPECT_EQ(nullptr,p);
}
TEST(fileToStr, nullFile){
    char *p = nullptr;
    string file = "../null.txt";
    EXPECT_EQ(-1,fileToStr(&file[0],&p));
    EXPECT_EQ(nullptr, p);
}
TEST(fileToStr, validFile){
    char *p = nullptr;
    string file = "../notnull.txt";
    EXPECT_EQ(0,fileToStr(&file[0],&p));
    EXPECT_NE(nullptr,p);
    EXPECT_EQ(24,strlen(p));
}
TEST(strToFile, combination){
    string str = "chars which will save to file";
    string file = "a.txt";
    EXPECT_EQ(0,strToFile(&file[0],&str[0],str.length()));
    char *p = nullptr;
    EXPECT_EQ(0,fileToStr(file.data(),&p));
    EXPECT_EQ(str.length(),strlen(p));
}
TEST(getOneWord, norepeat){
    Trie trie;
    string raw = "hello";
    const char *p = &raw[0];
    Word* word = nullptr;
    word = getOneWord(&p,trie);
    EXPECT_NE(nullptr, word);
    EXPECT_EQ(word->first, 'h');
    EXPECT_EQ(word->last, 'o');
    EXPECT_EQ(word->len, raw.length());
    EXPECT_EQ('\0',*p);
    delete word;
}
TEST(getOneWord, repeat){
    Trie trie;
    trie.insert("hello",5);
    string raw = "hello";
    const char *p = &raw[0];\
    Word* word = nullptr;
    word = getOneWord(&p,trie);
    EXPECT_EQ(nullptr,word);
    EXPECT_EQ('\0',*p);
}
TEST(getOneWord, null){
    Trie trie;
    string raw = "!@##$^&*()_+";
    const char *p = &raw[0];
    Word* word = nullptr;
    word = getOneWord(&p,trie);
    EXPECT_EQ(nullptr,word);
    EXPECT_EQ('\0',*p);
}
TEST(getOneWord, combination){
    Trie trie;
    trie.insert("hello",5);
    string raw = "!@#$^&*()_+hello";
    const char *p = &raw[0];
    Word* word = nullptr;
    word = getOneWord(&p,trie);
    EXPECT_EQ(nullptr,word);
    EXPECT_EQ('\0',*p);
}
TEST(getWords, repeat){
    string raw = "hello hello hello aaa bbb";
    WordList* words = nullptr;
    words = getWords(raw.data());
    ASSERT_NE(nullptr, words);
    EXPECT_EQ(1, words['h'-'a'].hlist.size());
    EXPECT_EQ(1, words['a'-'a'].hlist.size());
    EXPECT_EQ(1, words['b'-'a'].hlist.size());
    EXPECT_EQ(1, words['o'-'a'].tlist.size());
    EXPECT_EQ(1, words['a'-'a'].tlist.size());
    EXPECT_EQ(1, words['b'-'a'].tlist.size());
}