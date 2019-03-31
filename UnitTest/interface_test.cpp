#include "interface.hpp"
#include "gtest/gtest.h"

char *result[100];
char *r = "Algebra1Apple2Zoo1Elephant1Under1Fox1Dog1Moon1Leaf1Trick1Pseudopseudohypoparathyroidism";
char *raw = "The ReaSons why<they DO so are asa follows$$Firstly!!they$hope1to&lOOk smart*special ? I < the FollOWs/*BEfore,copY,eco1gAlaXy(hell)12345Killer@Length]NEED,open4people%%?Union??valUEax:you:zero*/looK";

TEST(MostCharacter,rawTestCharacter)
{
	struct WordList *wordlist = getWords(raw);
	std::list<std::list<Word*> >results;
	long len = MostCharacters(wordlist, 0, 0, results);
	EXPECT_EQ(len,64);
}
TEST(MostCharacter,rTestCharacter)
{
	struct WordList *wordlist = getWords(r);
	std::list<std::list<Word*> >results;
	long len = MostCharacters(wordlist, 0, 'n', results);
	EXPECT_EQ(len,34);
}
TEST(MostWords,rawTestWords1)
{
	struct WordList *wordlist = getWords(raw);
	std::list<std::list<Word*> >results;
	long len = MostWords(wordlist, 0, 0, results);
	EXPECT_EQ(len,13);
}
TEST(MostWords,rawTestWords2)
{
	struct WordList *wordlist = getWords(raw);
	std::list<std::list<Word*> >results;
	long len = MostWords(wordlist, 'h', 't', results);
	EXPECT_EQ(len,5);
}
TEST(MostWords,rTestWords)
{
	struct WordList *wordlist = getWords(r);
	std::list<std::list<Word*> >results;
	long len = MostWords(wordlist, 0, 't', results);
	EXPECT_EQ(len,3);
}
TEST(RequiredNumber,all)
{
	struct WordList *wordlist = getWords(raw);
	std::list<std::list<Word*> >results;
	long len = RequiredNumber(wordlist, 0, 0,12, results);
	EXPECT_EQ(len,2);
}
TEST(gen_chain_char,rawTestChainChar)
{
	int len = gen_chain_char(raw, 0, result, 0, 0, 1);
	EXPECT_EQ(len, 64);
}
TEST(gen_chain_word,rawTestChainWord1)
{
	int len = gen_chain_word(raw, 0, result, 0, 0);
	EXPECT_EQ(len, 13);
	len = gen_chain_word(raw, 0, result, 'h', 't');
}
TEST(gen_chain_word,rawTestChainWord2)
{
	int len = gen_chain_word(raw, 0, result, 'h', 't');
	EXPECT_EQ(len, 5);
}
TEST(gen_chain_number,rawTestChainNumber)
{
	std::list<std::list<char*> > result1;
	int len = gen_chain_number(raw, 0, result1, 0, 0,12);
	EXPECT_EQ(len, 2);
}
