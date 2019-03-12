/////////////////////////////////////////////////////
///
///This file contain common type used through this program
///
///////////////////////////////////////////////////
#ifndef __TYPE_HPP__
#define __TYPE_HPP__
#include <list>
struct Word{
    char first;
    char last;
    int len;
    char* raw;
};

struct ListNode{
	struct Word *w;
	Color color;
	long distance;
	ListNode *pi;
	long d;
	long f;
};

struct ListArray{
    list<ListNode> hlist;
    list<ListNode> tlist;
};
#endif
