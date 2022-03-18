#ifndef BOOK_H
#define BOOK_H

#include <time.h>

#define MAX_BOOK 20
#define BOOKS_LIMIT 3
#define MAX_TEXT 40

struct Book{
	int id;
	char name[MAX_TEXT];
	char author[MAX_TEXT];
	int year;
	int borrower;
	
};


struct Member{
	int id;
	char name[MAX_TEXT];
	time_t t_tjoin;
	int borrow[BOOKS_LIMIT];

	
};

struct Node{
	struct Book data;
	struct Node* next;
};

struct MemberNode{
	struct Member data;
	struct MemberNode* next;
};

#endif