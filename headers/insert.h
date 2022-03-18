#ifndef INSERT_H
#define INSERT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../headers/book.h"
#include "../headers/show.h" 

#define free_nodes(X) _Generic((X), \
                            struct Node*: free_nodes_Node,\
                            struct MemberNode*: free_nodes_Member \
                            )(X)

struct Node* reverse(struct Node* head);
char* input(char *text);
struct Book add_book();
void edit_book(struct Node* target);
struct Node* insert_book(struct Book book, struct Node* head);
struct Node* delete_book(struct Node* target, struct Node* head);
struct Node* get_book_bid(int id, struct Node* head);
void free_collections(struct Node* head); 
void free_nodes_Node(struct Node* head);



struct MemberNode* insert_member(struct Member member, struct MemberNode* head);
struct Member add_member();
struct MemberNode* delete_member(struct MemberNode* target, struct MemberNode* head);
struct MemberNode* get_member_bid(int id, struct MemberNode* head);
void borrow_book(struct Node* book_target, struct MemberNode* member_target);
void return_book(struct Book* book, struct Member* member);
void free_members(struct MemberNode* head);
void free_nodes_Member(struct MemberNode* head);


#endif