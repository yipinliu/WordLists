
#include "interface.hpp"
#include "algorithm.hpp"
#include "type.hpp"
#include <list>

using namespace std;

void charCopy(const char* src, char* dst, int len){
    for(int i = 0; i< len; i++){
        if(src[i]>='A'&&src[i]<='Z')
            dst[i] = src[i] - 'A' + 'a';
        else
        {
            dst[i] = src[i];
        }
        
    }
}

list<ListNode>::iterator getPosition(list<ListNode>& ls,ListNode& ln){
    auto end = ls.end();
    for(auto iter = ls.begin(); iter != end;iter++){
        if(iter->w->len < ln.w->len) return iter;
    }
    return end;
}



int gen_chain_word(char* words[], int len, char* result[], char head, char tail){
	WordList* wordlist = new WordList[26];
	for(int i = 0; i < len; i++){
		if(words[i] == nullptr){
			printf("Illegal word Found.\n");
			return -1;
		}
		int j = 0;
    	while(words[i][j] != '\0') j++;
		Word* word = new Word;
		word->raw = new char[j];
		word->len = j;
		charCopy(words[i], word->raw, j);
		word->first = word->raw[0];
		word->last = word->raw[j-1];
		ListNode hnode, tnode;
        hnode.w = word;
        tnode.w = word;
        auto& ls = wordlist[word->first-'a'].hlist;
        ls.insert(getPosition(ls,hnode),hnode);
        auto& tls = wordlist[word->last - 'a'].tlist;
        tls.insert(getPosition(tls,tnode),tnode);
	}
	char low_head = head, low_tail = tail;
	if(low_head != 0){
		if(low_head >= 'A' && low_head <= 'Z')
			low_head = low_head - 'A' + 'a';
		else if(!(low_head >= 'a' && low_head <= 'z')){
			printf("Illegal head character.\n");
			return -1;
		}
	}
	if(low_tail != 0){
		if(low_tail >= 'A' && low_tail <= 'Z')
			low_tail = low_tail - 'A' + 'a';
		else if(!(low_tail >= 'a' && low_tail <= 'z')){
			printf("Illegal tail character.\n");
			return -1;
		}
	}
	list<list<Word*> >results;
	long result_num;
	result_num = MostWords(wordlist, low_head, low_tail, results);
	if(result_num <= 0) return result_num;
    auto first_result = results.front();
    long chain_length = results.size();
    //result = (char **)malloc(chain_length * sizeof(char*));
    int k = 0;
    for(auto iter = first_result.begin(); iter != first_result.end(); iter++, k++){
    	int word_length = 0;
    	while((*iter)->raw[word_length] != '\0') word_length++;
    	char *result_word = (char *)malloc((word_length+1) * sizeof(char));
    	charCopy((*iter)->raw, result_word, word_length);
    	result_word[word_length] = '\0';
    	result[k] = result_word;
    }
    return result_num;
}


int gen_chain_char(char* words[], int len, char* result[], char head, char tail){
	WordList* wordlist = new WordList[26];
	for(int i = 0; i < len; i++){
		if(words[i] == nullptr){
			printf("Illegal word Found.\n");
			return -1;
		}
		int j = 0;
    	while(words[i][j] != '\0') j++;
		Word* word = new Word;
		word->raw = new char[j];
		word->len = j;
		charCopy(words[i], word->raw, j);
		word->first = word->raw[0];
		word->last = word->raw[j-1];
		ListNode hnode, tnode;
        hnode.w = word;
        tnode.w = word;
        auto& ls = wordlist[word->first-'a'].hlist;
        ls.insert(getPosition(ls,hnode),hnode);
        auto& tls = wordlist[word->last - 'a'].tlist;
        tls.insert(getPosition(tls,tnode),tnode);
	}
	char low_head = head, low_tail = tail;
	if(low_head != 0){
		if(low_head >= 'A' && low_head <= 'Z')
			low_head = low_head - 'A' + 'a';
		else if(!(low_head >= 'a' && low_head <= 'z')){
			printf("Illegal head character.\n");
			return -1;
		}
	}
	if(low_tail != 0){
		if(low_tail >= 'A' && low_tail <= 'Z')
			low_tail = low_tail - 'A' + 'a';
		else if(!(low_tail >= 'a' && low_tail <= 'z')){
			printf("Illegal tail character.\n");
			return -1;
		}
	}
	list<list<Word*> >results;
	long result_num;
	result_num = MostCharacters(wordlist, low_head, low_tail, results);
	if(result_num <= 0) return result_num;
    auto first_result = results.front();
    long chain_length = results.size();
    //result = (char **)malloc(chain_length * sizeof(char*));
    int k = 0;
    for(auto iter = first_result.begin(); iter != first_result.end(); iter++, k++){
    	int word_length = 0;
    	while((*iter)->raw[word_length] != '\0') word_length++;
    	char *result_word = (char *)malloc((word_length+1) * sizeof(char));
    	charCopy((*iter)->raw, result_word, word_length);
    	result_word[word_length] = '\0';
    	result[k] = result_word;
    }
    return first_result.size();
}


int gen_chain_number(char* words[], int len, std::list<std::list<char*> > &result, char head, char tail, int number){
	WordList* wordlist = new WordList[26];
	for(int i = 0; i < len; i++){
		if(words[i] == nullptr){
			printf("Illegal word Found.\n");
			return -1;
		}
		int j = 0;
    	while(words[i][j] != '\0') j++;
		Word* word = new Word;
		word->raw = new char[j];
		word->len = j;
		charCopy(words[i], word->raw, j);
		word->first = word->raw[0];
		word->last = word->raw[j-1];
		ListNode hnode, tnode;
        hnode.w = word;
        tnode.w = word;
        auto& ls = wordlist[word->first-'a'].hlist;
        ls.insert(getPosition(ls,hnode),hnode);
        auto& tls = wordlist[word->last - 'a'].tlist;
        tls.insert(getPosition(tls,tnode),tnode);
	}
	char low_head = head, low_tail = tail;
	if(low_head != 0){
		if(low_head >= 'A' && low_head <= 'Z')
			low_head = low_head - 'A' + 'a';
		else if(!(low_head >= 'a' && low_head <= 'z')){
			printf("Illegal head character.\n");
			return -1;
		}
	}
	if(low_tail != 0){
		if(low_tail >= 'A' && low_tail <= 'Z')
			low_tail = low_tail - 'A' + 'a';
		else if(!(low_tail >= 'a' && low_tail <= 'z')){
			printf("Illegal tail character.\n");
			return -1;
		}
	}
	list<list<Word*> >results;
	long result_num;
	result_num = RequiredNumber(wordlist, low_head, low_tail, number, results);
	if(result_num <= 0) return result_num;
    int k = 0;
    for(auto iterr = results.begin(); iterr != results.end(); iterr++){
    	list<char*> chain;
    for(auto iter = (*iterr).begin(); iter != (*iterr).end(); iter++, k++){
    	int word_length = 0;
    	while((*iter)->raw[word_length] != '\0') word_length++;
    	char *result_word = (char *)malloc((word_length+1) * sizeof(char));
    	charCopy((*iter)->raw, result_word, word_length);
    	result_word[word_length] = '\0';
    	chain.push_back(result_word);
    }
    	result.push_back(chain);
	}
    return result_num;
}

