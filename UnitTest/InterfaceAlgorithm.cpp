#include "interface.hpp"
#include "gtest/gtest.h"

char *result[100];
char *r = "Algebra1Apple2Zoo1Elephant1Under1Fox1Dog1Moon1Leaf1Trick1Pseudopseudohypoparathyroidism";
char *raw = "The ReaSons why<they DO so are asa follows$$Firstly!!they$hope1to&lOOk smart*special ? I < the FollOWs/*BEfore,copY,eco1gAlaXy(hell)12345Killer@Length]NEED,open4people%%?Union??valUEax:you:zero*/looK";

TEST(MostCharacters, all)
{
	struct WordList *wordlist = getWords(raw);
	std::list<std::list<Word*> >results;
	long len = MostCharacters(wordlist, 0, 0, results);
	EXPECT_EQ(len,64);

}
TEST(MostWords,all)
{
	struct WordList *wordlist = getWords(raw);
	std::list<std::list<Word*> >results;
	long len = MostWords(wordlist, 0, 0, results);
	EXPECT_EQ(len,13);
	len = MostWords(wordlist, 'h', 't' , results);
	EXPECT_EQ(len,5);
	wordlist = getWords(r);
	len = MostWords(wordlist, 0, 't', results);
	EXPECT_EQ(len,3);
}
TEST(RequiredNumber,all)
{
	struct WordList *wordlist = getWords(raw);
	std::list<std::list<Word*> >results;
	long len = RequiredNumber(wordlist, 0, 0,12, results);
	EXPECT_EQ(len,2);
}
TEST(gen_chain_char,all)
{
	int len = gen_chain_char(raw, 0, result, 0, 0, 1);
	EXPECT_EQ(len, 64);
	len = gen_chain_char(r, 0, result, 0, 0, 1);
	EXPECT_EQ(len, 34);
}
TEST(gen_chain_word,all)
{
	int len = gen_chain_word(raw, 0, result, 0, 0);
	EXPECT_EQ(len, 13);
	len = gen_chain_word(raw, 0, result, 'h', 't');
	len = gen_chain_word(r ,0, result, 0, 0);
	EXPECT_EQ(len, 4);
}
TEST(gen_chain_number,all)
{
	std::list<std::list<char*> > result1;
	int len = gen_chain_number(raw, 0, result1, 0, 0,12);
	EXPECT_EQ(len, 2);
	int len1 = gen_chain_number(r, 0, result1, 0, 0, 3);
	EXPECT_EQ(len1, 2);
}
