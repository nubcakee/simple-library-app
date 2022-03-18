#include <stdio.h>
#include "../headers/book.h"
#include "../headers/insert.h"


void print_book(struct Book p){
	struct Book* temp = &p;
	printf("%d.\n", p.id);
	printf(" Book name : %s\n", temp->name);
	printf(" Book author : %s\n", temp->author);
	printf(" Year published : %d\n", temp->year);
	printf(" book status : %d\n", temp->borrower);
	printf("-------------------------------------------------\n");
}
void print_collections(struct Node* head){
    struct Node* temp = head;
	int i = 1;
	printf("=============== Books Collections ===============\n");
    while(temp != NULL){
		printf("NODE : %d\n", i);
        print_book(temp->data);
        temp = temp->next;
		i++;
    }

	printf("=================================================\n");
}

void print_member(struct Member m, struct Node* collections){
	printf("id : %d\n", m.id);
	printf("name : %s\n", m.name);
	printf("Joined at : %s\n", ctime(&m.t_tjoin));

	int book_id;
	struct Node* book;
	int index = 1;
	printf("Books borrowed : \n");
	for(int i = 0; i< BOOKS_LIMIT;i++){
		book_id = m.borrow[i];
		if (book_id != 0){
			book = get_book_bid(book_id, collections);
			printf("\t%d. \"%s\" by %s\n", index, book->data.name, book->data.author);
			index++;
		}
		else printf("\t%d. (empty)\n", index);
		index++;
	}
	printf("-------------------------------------------------\n");
	
}

void print_members(struct MemberNode* members, struct Node* collections){
	printf("================= Members List =================\n");
	struct MemberNode* temp = members;
	while(temp != NULL){
		print_member(temp->data, collections);
		temp = temp->next;
	}
	printf("================================================\n");
}
