//the following two functions are standard dfs and topo sort algorithms
void DFS(struct WordList *wordlist, list<ListNode> &topo){
	for(int i = 0; i < 26; i++){
		for(auto iter = wordlist[i].hlist.begin(); iter != wordlist[i].hlist.end(); iter++){
			(*iter).color = WHITE;
		}
	}
	long time = 0;
	for(int i = 0; i < 26; i++){
		for(auto iter = wordlist[i].hlist.begin(); iter != wordlist[i].hlist.end(); iter++){
			if((*iter).color == WHITE){
				DFS_Visit((*iter), wordlist, time, topo);
			}
		}
	}
}

void DFS_Visit(struct ListNode &v, struct WordList *wordlist, long &time, list<ListNode> &topo){
	time = time + 1;
	v.d = time;
	v.color = GREY;
	char index = v.w->last - 'a';
	for (auto iter = wordlist[index].hlist.begin(); iter != wordlist[index].hlist.end(); iter++){
		if((*iter).color = WHITE){
			DFS_Visit(*iter, wordlist, time, topo);
		}
	}
	v.color = BLACK;
	time = time + 1;
	v.f = time;
	topo.push_front(&v);
}

//this function will find the longest path whose head is specified.
//@topo: the topo sequence of vertex 
//@currentlongest: the longest path found when specified a head
//@mode: define what longest mean, 0 represents most words and 1 represents most characters
//@tail: this is an optional argument, it must be 0 if there is no requirement for the tail of path
//@number: this is an optional argument, it must be -1 if there is no requirement for the length of path
long SingleSourceLongestPath(list<ListNode> &topo, list<list<Word*>> &currentlongest, list<ListNode>::iterator head, char mode, char tail, long number){
	(*head).distance = 0;
	long length = 0;
	list<ListNode> lastword;
	for(auto index = head + 1; index != topo.end(); index ++){
		(*index)->distance = NINF;
	}
	for(index = head; index != topo.end(); index++){
		if((*index)->distance != NINF){
			char adj = (*index)->w->last - 'a';
			for(auto i = wordlist[adj].hlist.begin(); i != wordlist[adj].hlist.end(); i++){
				if(mode){
					if ((*i)->distance < (*index)->distance + 1){
						(*i)->distance = (*index)->distance + 1;
						(*i)->pi = *index;
						if(length < (*i)->distance && tail == 0 && number == -1){
							length = (*i)->distance;
							lastword.clear();
							lastword.push_front(*i);
						}
						else if(length == (*i)->distance && tail == 0 && number == -1){
							lastword.push_front(*i);
						}
						else if(length < (*i)->distance && tail != 0 && (*i)->w->last == tail && number == -1){
							length = (*i)->distance;
							lastword.clear();
							lastword.push_front(*i);
						}
						else if(length == (*i)->distance && tail != 0 && (*i)->w->last == tail && number == -1){
							lastword.push_front(*i);
						}
						else if(number != -1 && (*i)->distance == number && tail == 0){
							length = number;
							lastword.push_front(*i);
						}
						else if(number != -1 && (*i)->distance == num && tail != 0 && (*i)->w->last == tail){
							length = number;
							lastword.push_front(*i);
						}
					}
				}
				else{
					if ((*i)->distance < (*index)->distance + (*index)->w->len){
						(*i)->distance = (*index)->distance + (*index)->w->len;
						(*i)->pi = *index;
						if(length < (*i)->distance && tail == 0 && number == -1){
							length = (*i)->distance;
							lastword.clear();
							lastword.push_front(*i);
						}
						else if(length == (*i)->distance && tail == 0 && number == -1){
							lastword.push_front(*i);
						}
						else if(length < (*i)->distance && tail != 0 && (*i)->w->last == tail && number == -1){
							length = (*i)->distance;
							lastword.clear();
							lastword.push_front(*i);
						}
						else if(length == (*i)->distance && tail != 0 && (*i)->w->last == tail && number == -1){
							lastword.push_front(*i);
						}
						else if(number != -1 && (*i)->distance == number && tail == 0){
							length = number;
							lastword.push_front(*i);
						}
						else if(number != -1 && (*i)->distance == num && tail != 0 && (*i)->w->last == tail){
							length = number;
							lastword.push_front(*i);
						}
					}
				}
			}
		}
	}
	for(auto j = lastword.begin(); j != lastword.end(); j++){
		list<word*> longest;
		auto x = *j;
		while(x->distance != 0){
			longest.push_front(x.w);
			x = x->pi;
		}
		longest.push_front(x.w);
		currentlongest.push_front(longest);
	}
	return length;
}

long MostWords(struct WordList *wordlist, char head, char tail, list<list<Word*>> &result){
	long chainlength = 0;
	long currentlength = 0;
	list<ListNode> topo;
	list<list<Word*>> currentlongest;
	DFS(wordlist, topo);
	for(auto index = topo.begin(); index != topo.end(); index++){
		if(!((head == 0 || (head >= 'a' && head <= 'z')) && (tail == 0 || (tail >= 'a' && tail <= 'z')))){
			return NOTENGLISHLETTER;
		}
		else if(head == 0){
			currentlength = SingleSourceLongestPath(topo, currentlongest, index, 0, tail, -1);
			if(chainlength < currentlength){
				chainlength = currentlength;
				result.clear();
				result.merge(currentlongest);
			}
			else if(chainlength == currentlength && currentlength != 0){
				result.merge(currentlongest);
			}
		}
		else if('a' <= head && head <= 'z' && (*)index.w->first == head){
			currentlength = SingleSourceLongestPath(topo, currentlongest, index, 0, tail, -1);
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
	return chainlength;
}

long MostCharacters(struct WordList *wordlist, char head, char tail, list<list<Word*>> &result){
	long chainlength = 0;
	long currentlength = 0;
	list<ListNode> topo;
	list<list<Word*>> currentlongest;
	DFS(wordlist, topo);
	for(auto index = topo.begin(); index != topo.end(); index++){
		if(!((head == 0 || (head >= 'a' && head <= 'z')) && (tail == 0 || (tail >= 'a' && tail <= 'z')))){
			return NOTENGLISHLETTER;
		}
		else if(head == 0){
			currentlength = SingleSourceLongestPath(topo, currentlongest, index, 1, tail, -1);
			if(chainlength < currentlength){
				chainlength = currentlength;
				result.clear();
				result.merge(currentlongest);
			}
			else if(chainlength == currentlength && currentlength != 0){
				result.merge(currentlongest);
			}
		}
		else if('a' <= head && heads <= 'z' && (*)index.w->first == head){
			currentlength = SingleSourceLongestPath(topo, currentlongest, index, 1, tail, -1);
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
	return chainlength;
}

long RequiredNumber(struct WordList *wordlist, char head, char tail, long number, list<list<Word*>> &result){
	long chainnumber = 0;
	list<ListNode> topo;
	list<list<Word*>> currentchain;
	DFS(wordlist, topo);
	for(auto index = topo.begin(); index != topo.end(); index++){
		if(!((head == 0 || (head >= 'a' && head <= 'z')) && (tail == 0 || (tail >= 'a' && tail <= 'z')))){
			return NOTENGLISHLETTER;
		}
		else if(head == 0){
			currentlength = SingleSourceLongestPath(topo, currentlongest, index, 1, tail, number);
			if(number == currentlength){
				result.merge(currentlongest);
			}
		}
		else if('a' <= head && head <= 'z' && (*)index.w->first == head){
			currentlength = SingleSourceLongestPath(topo, currentlongest, index, 1, tail, number);
			if(number == currentlength){
				result.merge(currentlongest);
			}
		}
	}
	chainnumber = result.size();
	if(chainnumber == 0)
		return NOTFOUND;
	return chainnumber;
}