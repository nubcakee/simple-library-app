#ifndef FILE_H
#define FILE_H

void save_books(struct Node* collections);
struct Node* load_books();

void save_members(struct MemberNode* members);
struct MemberNode* load_members();

#endif