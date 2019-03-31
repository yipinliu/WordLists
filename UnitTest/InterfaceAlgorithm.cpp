#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project2/interface.hpp"
#include "../Project2/type.hpp"
#include "../Project2/IO.hpp"
#include "../Project2/algorithm.hpp"

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
		TEST_METHOD(TestMethod1)
		{
			struct WordList *wordlist = getWords(raw);
			std::list<std::list<Word*> >results;
			long len = MostCharacters(wordlist, 0, 0, results);
			Assert::IsTrue(len == 64);

		}
		TEST_METHOD(TestMethod2)
		{
			struct WordList *wordlist = getWords(raw);
			std::list<std::list<Word*> >results;
			long len = MostWords(wordlist, 0, 0, results);
			Assert::IsTrue(len == 13);
			len = MostWords(wordlist, 'h', 't' , results);
			Assert::IsTrue(len == 5);
			wordlist = getWords(r);
			len = MostWords(wordlist, 0, 't', results);
			Assert::IsTrue(len == 3);
		}
		TEST_METHOD(TestMethod3)
		{
			struct WordList *wordlist = getWords(raw);
			std::list<std::list<Word*> >results;
			long len = RequiredNumber(wordlist, 0, 0,12, results);
			Assert::IsTrue(len == 2);
		}
		TEST_METHOD(TestMethod4)
		{
			int len = gen_chain_char(raw, 0, result, 0, 0, 1);
			Assert::IsTrue(len == 64);
			len = gen_chain_char(r, 0, result, 0, 0, 1);
			Assert::IsTrue(len == 34);
		}
		TEST_METHOD(TestMethod5)
		{
			int len = gen_chain_word(raw, 0, result, 0, 0);
			Assert::IsTrue(len == 13);
			len = gen_chain_word(raw, 0, result, 'h', 't');
			len = gen_chain_word(r ,0, result, 0, 0);
			Assert::IsTrue(len == 4);
		}
		TEST_METHOD(TestMethod6)
		{
			std::list<std::list<char*> > result1;
			int len = gen_chain_number(raw, 0, result1, 0, 0,12);
			Assert::IsTrue(len == 2);
			int len1 = gen_chain_number(r, 0, result1, 0, 0, 3);
			Assert::IsTrue(len1 == 2);
		}

	};
}
