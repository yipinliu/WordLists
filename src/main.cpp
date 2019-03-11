#include <iostream>
#include <string.h>
#include <stdio.h>
#include <list>
#define MAXSIZE 1000
using namespace std;

struct Word{
	char first;
	char last;
	int len;
	char raw[MAXSIZE];
};
struct ListNode{
    struct Word w;
    int color;
};
struct WordList{
    list<ListNode> hList;
    list<ListNode> tList;
};
struct WordList wordlist[26];
struct ListNode listnode;
//list<Word> result1;
//list<Word> result2;
//list<list<Word>> result3;
FILE *infile,*outfile;
char ch;  //char got from txt
struct Word new_word;// word got from txt

void getch()
{
    ch = getc(infile);
}
void getWord()
{

	char cword[MAXSIZE];
	int cword_length = 0;
	getch();
	if(ch < 'a' || ch > 'z')
		getch();
	if((ch >= 'a') && (ch <= 'z'))
	{	
		while(ch >= 'a' && ch <= 'z'){
			cword[cword_length++] = ch;
			getch();
		}
		cword[cword_length] = 0;
		strcpy(new_word.raw,cword);
		new_word.first = cword[0];
		new_word.last = cword[cword_length - 1];
		new_word.len = cword_length;
	}
}



int main(int argc,char *argv[])
{
    char absolute_path[512];
    char head; 
    char tail;
    int search_num;
	if(argc == 3)
    {
        if(!strcmp(argv[1],"-w") || !strcmp(argv[1],"-c"))
        {
            strcpy(absolute_path,argv[2]); //1. & 2.  copy absolute path;
        }
        else
        {
            cout<<"error1!"<<endl;
            return 0;
        }
    }
    else if (argc == 5)
    {
        strcpy(absolute_path,argv[4]); // copy absolute path;
        if(!strcmp(argv[1],"-h"))
        {
            head = argv[2][0]; //3. get head letter which is wanted to search 
        }
        else if(!strcmp(argv[1],"-t"))
        {
            tail = argv[2][0]; //4. get tail letter which is wanted to search 
        }
        else if(!strcmp(argv[1],"-n"))
        {
            search_num = argv[2][0];
        }
        else 
        {
            cout<<"error2!"<<endl;
            return 0;
        }
    }
    else if(argc == 7)
    {
        if((!strcmp(argv[1],"-h")) && (!strcmp(argv[3],"-t")))
        {
            head = argv[2][0];
            tail = argv[4][0];
            strcpy(absolute_path,argv[6]);
        }
        else if((!strcmp(argv[1],"-t")) && (!strcmp(argv[3],"-h")))
        {
            head = argv[4][0];
            tail = argv[2][0];
            strcpy(absolute_path,argv[6]);
        }
        else
        {
            {
                cout<<"error3!"<<endl;
                return 0;
            }
        }
        
    }
    else
    {
        cout<<"error4!"<<endl;
        return 0;
    }
    if((infile = fopen(absolute_path,"r")) == NULL ) //open file
    {
        cout<<"file not exist!"<<endl;
        return 0;
    }
    // get word from file 
    getch(); 
    while(ch != EOF)
	{
		if(ch < 'a'|| ch >'z')
		{
			getch();
		}
		else
		{
			fseek(infile,-1,SEEK_CUR);	
			getWord();
			for(int i=0;i<26;i++)
			{
				strcpy(listnode.w.raw,new_word.raw);
                listnode.w.first = new_word.first;
                listnode.w.last = new_word.last;
                listnode.w.len = new_word.len;
                //listnode.color = 0;
                if(new_word.first == i+97)
                {
                    wordlist[i].hList.push_back(listnode);
                }
                if(new_word.last == i+97)
                {
                    wordlist[i].tList.push_back(listnode);
                }
			}
		}
		getch(); 
	}
	/*
    if(!strcmp(argv[1],"-w"))
    {
	    MostWords(wordlist,head,tail,&result1);
    }
    else if(!strcmp(argv[1],"-c"))
    {
	    MostCharacters(wordlist,head,tail,&result2);
    }
    else if()
    {
       RequiredNumber(wordlist,head,tail,&result3);
    }
    */
    /* maybe follow these step:
    1. parse the command line;
    2. get the data from input
    3. get the query from input
    4. call different query function based on query type
    5. output
    */
    system("pause");
    return 0;
}
