#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project2/interface.hpp" //you should change path  
#include "../Project2/type.hpp"  // if your project is not named Project2
#include "../Project2/IO.hpp"  //this path only adapts to this project
#include "../Project2/algorithm.hpp"
#include <list>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
char *result[100];
char *r = "Algebra1Apple2Zoo1Elephant1Under1Fox1Dog1Moon1Leaf1Trick1Pseudopseudohypoparathyroidism";
char *raw = "The ReaSons why<they DO so are asa follows$$Firstly!!they$hope1to&lOOk smart*special ? I < the FollOWs/*BEfore,copY,eco1gAlaXy(hell)12345Killer@Length]NEED,open4people%%?Union??valUEax:you:zero*/looK";
namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(test_MostCharacter1)
		{
			struct WordList *wordlist = getWords(raw);
			std::list<std::list<Word*> >results;
			long len = MostCharacters(wordlist, 0, 0, results);
			Assert::IsTrue(len == 64);
		}
		TEST_METHOD(test_MostCharacter2)
		{
			struct WordList *wordlist = getWords(r);
			std::list<std::list<Word*> >results;
			long len = MostCharacters(wordlist, 0, 'n', results);
			Assert::IsTrue(len == 34);
		}
		TEST_METHOD(test_MostWord1)
		{
			struct WordList *wordlist = getWords(raw);
			std::list<std::list<Word*> >results;
			long len = MostWords(wordlist, 0, 0, results);
			Assert::IsTrue(len == 13);
		}
		TEST_METHOD(test_MostWord2)
		{
			struct WordList *wordlist = getWords(r);
			std::list<std::list<Word*> >results;
			long len = MostWords(wordlist, 0, 't', results);
			Assert::IsTrue(len == 3);
		}
		TEST_METHOD(test_RequiredNum)
		{
			struct WordList *wordlist = getWords(raw);
			std::list<std::list<Word*> >results;
			long len = RequiredNumber(wordlist, 0, 0,12, results);
			Assert::IsTrue(len == 2);
		}
		TEST_METHOD(test_chain_char)
		{
			int len = gen_chain_char(raw, 0, result, 0, 0, 1);
			Assert::IsTrue(len == 64);
		}
		TEST_METHOD(test_chain_word)
		{
			int len = gen_chain_word(raw, 0, result, 0, 0);
			Assert::IsTrue(len == 13);
		}
	
		TEST_METHOD(test_chain_number1)
		{
			std::list<std::list<char*> > result1;
			int len = gen_chain_number(raw, 0, result1, 0, 0,12);
			Assert::IsTrue(len == 2);
		}
		TEST_METHOD(test_chain_number2)
		{
			std::list<std::list<char*> > result1;
			int len1 = gen_chain_number(r, 0, result1, 0, 0, 3);
			Assert::IsTrue(len1 == 2);
		}

	};
}
