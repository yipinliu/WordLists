#include "algorithm.hpp"
#include "type.hpp"
#include <string.h>
using namespace std;
//the following two functions are standard dfs and topo sort algorithms
void DFS_Visit(struct ListNode &v, struct WordList *wordlist, long &time, list<ListNode*> &topo){
	time = time + 1;
	v.d = time;
	v.color = GREY;
	char index = v.w->last - 'a';
	for (auto iter = wordlist[index].hlist.begin(); iter != wordlist[index].hlist.end(); iter++){
		if((*iter).color == WHITE){
			DFS_Visit(*iter, wordlist, time, topo);
		}
	}
	v.color = BLACK;
	time = time + 1;
	v.f = time;
	topo.push_front((ListNode *)&v);
}

void DFS(struct WordList *wordlist, list<ListNode*> &topo, char head, char tail){
	int i = 0;
	for(i = 0; i < 26; i++){
		for(auto iter = wordlist[i].hlist.begin(); iter != wordlist[i].hlist.end(); iter++){
			(*iter).color = WHITE;
		}
	}
	long time = 0;
	if(head == 0){
		i = 0;
	}
	else if(head >= 'a' && head <= 'z'){
		i = head - 'a';
	}
	for(; i < 26; i++){
		for(auto iter = wordlist[i].hlist.begin(); iter != wordlist[i].hlist.end(); iter++){
			if((*iter).color == WHITE && (tail == 0 || (tail != 0 && (*iter).w->last != tail))){
				DFS_Visit((*iter), wordlist, time, topo);
			}
			else if((*iter).color == WHITE && (tail != 0 && (*iter).w->last == tail)){
				continue;
			}
		}
		for(auto iter = wordlist[i].hlist.begin(); iter != wordlist[i].hlist.end(); iter++){
			if((*iter).color == WHITE)
				DFS_Visit((*iter), wordlist, time, topo);
		}
	}
	for(i = head - 'a'; i >= 0 ; i--){
		for(auto iter = wordlist[i].hlist.begin(); iter != wordlist[i].hlist.end(); iter++){
			if((*iter).color == WHITE && (tail == 0 || (tail != 0 && (*iter).w->last != tail))){
				DFS_Visit((*iter), wordlist, time, topo);
			}
			else if((*iter).color == WHITE && (tail != 0 && (*iter).w->last == tail)){
				continue;
			}
		}
		for(auto iter = wordlist[i].hlist.begin(); iter != wordlist[i].hlist.end(); iter++){
			if((*iter).color == WHITE)
				DFS_Visit((*iter), wordlist, time, topo);
		}
	}
	/*if(tail >= 'a' && tail <= 'z'){
		list<ListNode*> topo_temp;
		list<ListNode*> tail_temp;
		topo_temp.merge(topo);
		for(auto iter = topo_temp.begin(); iter != topo_temp.end(); iter++){
			if((*iter)->w->last == tail){
				tail_temp.push_back((*iter));
			}
			else{
				topo.push_back((*iter));
			}
		}
		for(auto iter = tail_temp.begin(); iter != tail_temp.end(); iter++){
			topo.push_back((*iter));
		}
		for(auto iter = topo.begin(); iter != topo.end(); iter++){
			printf("%s\n",(*iter)->w->raw);
		}
	}*/
	/*for(auto iter = topo.begin(); iter != topo.end(); iter++){
			printf("%s\n",(*iter)->w->raw);
		}*/
}


//this function will find the longest path whose head is specified.
//@topo: the topo sequence of vertex 
//@currentlongest: the longest path found when specified a head
//@mode: define what longest mean, 0 represents most words and 1 represents most characters
//@tail: this is an optional argument, it must be 0 if there is no requirement for the tail of path
//@number: this is an optional argument, it must be -1 if there is no requirement for the length of path
long SingleSourceLongestPath(struct WordList *wordlist, list<ListNode*> &topo, list<list<Word*> > &currentlongest,
							 list<ListNode*>::iterator head, char mode, char tail, long number){
	for(auto index2 = topo.begin(); index2 != topo.end(); index2++){
		(*index2)->distance = NINF;
		(*index2)->pi = nullptr;

	}
	(*head)->distance = 0;
	long length = 0;
	list<ListNode> lastword;
	for(auto index = head; index != topo.end(); index++){
		if((*index)->distance != NINF){
			char adj = (*index)->w->last;
			auto k = index;
			k++;
			for(; k != topo.end(); k++){
				auto i = *k;
				if ((*i).w->first != adj)
					continue;
				if(!mode && ((*i).distance < ((*index)->distance + 1))){
					(*i).distance = (*index)->distance + 1;
					(*i).pi = *index;
				}
				else if(mode && ((*i).distance < ((*index)->distance + (*i).w->len))){
					(*i).distance = (*index)->distance + (*i).w->len;
					//printf("%ld",(*i).w->len);
					(*i).pi = *index;
				}
				if(length < (*i).distance && tail == 0 && number == -1){
					length = (*i).distance;
					lastword.clear();
					lastword.push_front(*i);
				}
				else if(length == (*i).distance && tail == 0 && number == -1){
					int flag = 0;
					for(auto iter = lastword.begin(); iter != lastword.end(); iter++){
						if(strcmp((*iter).w->raw, (*i).w->raw) == 0)
							flag = -1;
					}
					if(flag == 0)
						lastword.push_front(*i);
				}
				else if(length < (*i).distance && tail != 0 && (*i).w->last == tail && number == -1){
					length = (*i).distance;
					lastword.clear();
					lastword.push_front(*i);
				}
				else if(length == (*i).distance && tail != 0 && (*i).w->last == tail && number == -1){
					int flag = 0;
					for(auto iter = lastword.begin(); iter != lastword.end(); iter++){
						if(strcmp((*iter).w->raw, (*i).w->raw) == 0)
							flag = -1;
					}
					if(flag == 0)
						lastword.push_front(*i);
				}
				else if(number != -1 && (*i).distance == number - 1 && tail == 0 && !mode){
					length = number - 1; 
					int flag = 0;
					for(auto iter = lastword.begin(); iter != lastword.end(); iter++){
						if(strcmp((*iter).w->raw, (*i).w->raw) == 0)
							flag = -1;
					}
					if(flag == 0)
						lastword.push_front(*i);
				}
				else if(number != -1 && (*i).distance == number - 1 && tail != 0 && (*i).w->last == tail && !mode){
					length = number - 1;
					int flag = 0;
					for(auto iter = lastword.begin(); iter != lastword.end(); iter++){
						if(strcmp((*iter).w->raw, (*i).w->raw) == 0)
							flag = -1;
					}
					if(flag == 0)
						lastword.push_front(*i);
				}
				}
			}
		}
	if(lastword.size() != 0){
		for(auto j = lastword.begin(); j != lastword.end(); j++){
		list<Word*> longest;
		auto x = &(*j);
		while(x->distance != 0){
			longest.push_front(x->w);
			x = x->pi;
		}
		longest.push_front(x->w);
		currentlongest.push_front(longest);
	}
	}
	else{
		list<Word*> longest;
		longest.push_front((*head)->w);
		currentlongest.push_front(longest);
	}
	
	//printf("%ld------",length);

	if(!mode)
		return length+1;
	else
		return length+(*head)->w->len;
}

long MostWords2(struct WordList *wordlist, char head, char tail, list<list<Word*> > &result){
	long chainlength = 0;
	long currentlength = 0;
	list<ListNode*> topo;
	list<list<Word*> > currentlongest;
	DFS(wordlist, topo, head, tail);
	//printf("lll");
	//printf("----%d----",topo.size());

	for(auto index = topo.begin(); index != topo.end(); index++){
		currentlongest.clear();
		if(!((head == 0 || (head >= 'a' && head <= 'z')) && (tail == 0 || (tail >= 'a' && tail <= 'z')))){
			return NOTENGLISHLETTER;
		}
		else if(head == 0){
			currentlength = SingleSourceLongestPath(wordlist, topo, currentlongest, index, 0, tail, -1);
			if(chainlength < currentlength){
				chainlength = currentlength;
				result.clear();
				//printf("..............%d............\n",currentlength);
				result.merge(currentlongest);
				//printf(".............%d..........\n",result.size());
			}
			else if(chainlength == currentlength && currentlength != 0){
				//printf("..............%d............\n",currentlength);
				result.merge(currentlongest);
				//printf(".............%d..........\n",result.size());
			}
		}
		else if('a' <= head && head <= 'z' && (*index)->w->first == head){
			currentlength = SingleSourceLongestPath(wordlist, topo, currentlongest, index, 0, tail, -1);
			if(chainlength < currentlength){
				chainlength = currentlength;
				result.clear();
				result.merge(currentlongest);
			}
			else if(chainlength == currentlength && currentlength != 0){
				result.merge(currentlongest);
			}
		}
		
	}
	if(chainlength == 0)
		return NOTFOUND;
	/*printf("----------------%d\n",result.size());
	for(auto j = result.begin(); j!=result.end(); j++){
		for(auto k = (*j).begin(); k != (*j).end(); k++){
			printf("%s",(*k)->raw);
		}
		printf("\n");
	}*/
	return chainlength;
}

long MostWords(struct WordList *wordlist, char head, char tail, list<list<Word*> > &result){
	list<list<Word*> > temp_result;
	long chainlength = 0;
	long currentlength = 0;
	if(tail != 0 && head == 0){
		for(int i = 'a';i < 'z'; i++){
			temp_result.clear();
			currentlength=MostWords2(wordlist,i,tail,temp_result);
			if(currentlength > chainlength){
				result.clear();
				result.merge(temp_result);
				chainlength = currentlength;
			}
			else if(currentlength == chainlength && currentlength != 0){
				result.merge(temp_result);
			}
		}
	}
	else{
		chainlength=MostWords2(wordlist,head,tail,result);
	}
	if(chainlength == 0)
		return NOTFOUND;
	for(auto iter = result.begin(); iter != result.end(); iter++){
		if((*iter).size() == 1)
			result.erase(iter);
	}
	if(result.size() == 0)
		return NOTFOUND;
	return chainlength;
}

long MostCharacters2(struct WordList *wordlist, char head, char tail, list<list<Word*> > &result){
	long chainlength = 0;
	long currentlength = 0;
	list<ListNode*> topo;
	list<list<Word*> > currentlongest;
	DFS(wordlist, topo, head, tail);
	for(auto index = topo.begin(); index != topo.end(); index++){
		currentlongest.clear();
		if(!((head == 0 || (head >= 'a' && head <= 'z')) && (tail == 0 || (tail >= 'a' && tail <= 'z')))){
			return NOTENGLISHLETTER;
		}
		else if(head == 0){
			currentlength = SingleSourceLongestPath(wordlist, topo, currentlongest, index, 1, tail, -1);
			if(chainlength < currentlength){
				chainlength = currentlength;
				result.clear();
				result.merge(currentlongest);
			}
			else if(chainlength == currentlength && currentlength != 0){
				result.merge(currentlongest);
			}
		}
		else if('a' <= head && head <= 'z' && (*index)->w->first == head){
			currentlength = SingleSourceLongestPath(wordlist, topo, currentlongest, index, 1, tail, -1);
			if(chainlength < currentlength){
				chainlength = currentlength;
				result.clear();
				result.merge(currentlongest);
			}
			else if(chainlength == currentlength && currentlength != 0){
				result.merge(currentlongest);
			}
		}
		
	}
	if(chainlength == 0)
		return NOTFOUND;
	/*printf("------------------------%d\n",result.size());
	for(auto j = result.begin(); j!=result.end(); j++){
		for(auto k = (*j).begin(); k != (*j).end(); k++){
			printf("%s",(*k)->raw);
		}
		printf("\n");
	}*/
	return chainlength;
}

long MostCharacters(struct WordList *wordlist, char head, char tail, list<list<Word*> > &result){
	list<list<Word*> > temp_result;
	long chainlength = 0;
	long currentlength = 0;
	if(tail != 0 && head == 0){
		for(int i = 'a';i < 'z'; i++){
			temp_result.clear();
			currentlength=MostCharacters2(wordlist,i,tail,temp_result);
			if(currentlength > chainlength){
				result.clear();
				result.merge(temp_result);
				chainlength = currentlength;
			}
			else if(currentlength == chainlength && currentlength != 0){
				result.merge(temp_result);
			}
		}
	}
	else{
		chainlength=MostCharacters2(wordlist,head,tail,result);
	}
	if(chainlength == 0)
		return NOTFOUND;
	for(auto iter = result.begin(); iter != result.end(); iter++){
		if((*iter).size() == 1)
			result.erase(iter);
	}
	if(result.size() == 0)
		return NOTFOUND;
	return chainlength;
}

long RequiredNumber2(struct WordList *wordlist, char head, char tail, long number, list<list<Word*> > &result){
	long chainnumber = 0;
	long currentlength = 0;
	list<ListNode*> topo;
	list<list<Word*> > currentchain;
	list<list<Word*> > currentlongest;
	list<list<Word*> > temp_result;
	DFS(wordlist, topo, head, tail);
	for(auto index = topo.begin(); index != topo.end(); index++){
		currentlongest.clear();
		if(!((head == 0 || (head >= 'a' && head <= 'z')) && (tail == 0 || (tail >= 'a' && tail <= 'z')))){
			return NOTENGLISHLETTER;
		}
		else if(head == 0){
			currentlength = SingleSourceLongestPath(wordlist, topo, currentlongest, index, 0, tail, number);
			if(number == currentlength){
				result.merge(currentlongest);
			}
		}
		else if('a' <= head && head <= 'z' && (*index)->w->first == head){
			currentlength = SingleSourceLongestPath(wordlist, topo, currentlongest, index, 0, tail, number);
			if(number == currentlength){
				result.merge(currentlongest);
			}
		}
	}
		for(auto i = result.begin(); i != result.end(); i++){
		if((*i).front()->first == (*i).back()->last){
			list<Word*> temp;
			long size = (*i).size();
			for(auto x = (*i).begin(); x != (*i).end(); x++){
				temp.push_back(*x);
			}
			for(int k = 0; k < size - 1; k++){
				Word* front = temp.front();
				temp.pop_front();
				temp.push_back(front);
				if((head == 0 && tail == 0) || (head != 0 && temp.front()->first == head && tail == 0) 
					|| (head !=0 && temp.front()->first == head && tail != 0 && temp.back()->last == tail)
					|| (head == 0 && tail != 0 && temp.back()->last == tail))
				result.push_front(temp);
			}
		}
	}
	
	chainnumber = result.size();
	if(chainnumber == 0)
		return NOTFOUND;
	return chainnumber;
}

long RequiredNumber(struct WordList *wordlist, char head, char tail, long number, list<list<Word*> > &result){
	list<list<Word*> > temp_result;
	int chainnumber=0;
	int totalnumber=0;
	if(tail != 0 && head == 0){
		for(int i = 'a';i < 'z'; i++){
			temp_result.clear();
			chainnumber=RequiredNumber2(wordlist,i,tail,number,temp_result);
			if(chainnumber > 0){
				result.merge(temp_result);
				totalnumber+=chainnumber;
			}
		}
	}
	else{
		chainnumber=RequiredNumber2(wordlist,head,tail,number,result);
		totalnumber = chainnumber;
	}
	if(totalnumber == 0)
		return NOTFOUND;
	return totalnumber;
}
