# Lab01设计文档

### 一、基本功能实现

####1、最多单词数量的单词链求解

**问题描述：**

求最长单词链的问题可以转化为有向有环图的最长简单路径求解问题：

每个单词可以看做图的一个顶点，当单词A的尾字母与单词B的首字母一样时，产生一条从A到B的有向边，每条边的权重为1，我们要求解的就是这个图中的最长简单路径。

**求解方法：**

可以借鉴单源最短路径求解的Dijkstra算法，将路径松弛操作修改为$d_i(x) = max\{d_i(x), l_{ji}(x) + d_j(x)\}$，依次对每个顶点进行松弛，最后得到$d_(x)$最大的顶点，它就是最长单词链的最后一个结点，从这个结点向前回溯即可得到完整的单词链，对所有的顶点都应用一次上面的算法，得到的最长单词链中最长的即为所求。

**优化操作：**

上面描述的算法时间复杂度比较高，故为了降低程序运行时间，我们先将整个图进行一次拓扑排序，然后依照拓扑排序的次序进行松弛，每一个顶点在应用单源最长路径算法时可以只对它后面(拓扑序)的结点进行松弛操作，故可以大大降低时间复杂度。

**关键代码：**

```c++
long MostWords2(struct WordList *wordlist, char head, char tail, list<list<Word*> > &result){
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
	return chainlength;
}
```

####2、最多字符数的单词链求解

这一需求的求解方法与上面的需求大致相同，只是在构建图的过程中边A->B的权重是单词B的字符数，然后应用上面相同的算法即可求解。

**关键代码：**

```c++
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
	return chainlength;
}
```

#### 3、指定单词数的单词链求解

**求解方法：**

这一需求有两种求解方法：

**1、**可以使用广度优先搜索BFS搜索深度为指定单词数的单词，然后回溯形成完整单词链即可。要求解所有的指定长度单词链，对所有的单词应用上述算法，返回所有符合条件的单词链。

**2、**可以在上面求解最长单词链的过程中求解此问题，在松弛顶点的时候，一旦某个时间顶点的距离正好符合单词数的要求，就立即返回这个单词链，这种算法与实现其他需求的算法基本一致，可以共用函数减少代码量。

**关键代码：**

```c++
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
```

#### 4、指定首尾字符的单词链求解

这一需求不能单独存在，必须与其他需求组合起来实现：

**与最多单词数量或者最多字符数的单词链需求组合：**

**求解方法：**

若指定单词链的首字符，则我们在求解最长单词链的过程中不必要对每一个顶点都应用一次单源最长路径算法，只需要对符合首字符要求的单词所在的顶点应用单源最长路径算法即可，最后从得到的局部最长路径中选择全局最长路径即可。

若指定单词链的尾字符，则在单源最长路径算法最后选择局部最长路径时，加入尾字符是否满足要求的条件即可。

若同时指定首尾字符，则将上述算法结合即可。

**关键代码：**(部分已在上面列出的关键代码中实现)

```c++
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

	if(!mode)
		return length+1;
	else
		return length+(*head)->w->len;
}
```

**与指定单词数量的单词链需求组合：**

若指定单词的首字符，同理只需要对首字符符合要求的顶点应用指定单词数量的算法；若指定尾字符，则在确定结果时需要加一个条件判断尾字符是否满足要求。

关键代码在上面的与最长单词链组合的需求的关键代码中已实现。