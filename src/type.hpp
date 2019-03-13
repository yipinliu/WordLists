/////////////////////////////////////////////////////
///
///This file contain common type used through this program
///
///////////////////////////////////////////////////
#ifndef __TYPE_HPP__
#define __TYPE_HPP__
#include <list>
enum Color{
    BLACK = 0,
    WHITE,
    GREY
};
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
    ListNode():
        w(nullptr),color(WHITE),distance(0),pi(nullptr),
        d(0),f(0){}
};

struct WordList{
    std::list<ListNode> hlist;
    std::list<ListNode> tlist;
};
#endif
