#ifndef SHOW_H
#define SHOW_H

#define M "[MESSAGE]"
#define S "[SUCCESS]"
#define F "[FAILED]"

void print_book(struct Book p);
void print_collections(struct Node* head);
void print_member(struct Member m, struct Node* collections);
void print_members(struct MemberNode* members, struct Node* collections);

#endif