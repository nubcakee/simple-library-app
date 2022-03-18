#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/book.h"
#include "../headers/insert.h"
#include "../headers/show.h"
#include "../headers/file.h"


int main(){
	struct Node* collections;
	struct MemberNode* members;
	
	collections = NULL;
	members = NULL;

	struct Book book;
	struct Member member;
	char* command;
	char* book_id;
	char* member_id;

	struct Node* target;
	struct MemberNode* member_target;

	collections = load_books();
	members = load_members();

	while (1){
		printf("\n");
		command = input("Enter your command :\n\ta : add book to collections\taa : add member\n\te : edit book\t\t\tdd : delete member\n\td : delete book\t\t\tbb : borrow book\n\ts : print all collections\trb : return book\n\t\t\t\t\tss : print all members\t\t0 : exit\n >>> ");
		
		if(strcmp(command, "a")== 0){
			book = add_book();
			collections =  insert_book(book, collections);
		}

		else if(strcmp(command, "e")==0){
			book_id = input("Enter book's id : ");
	
			target = get_book_bid(atol(book_id), collections);
			if (target != NULL){
				edit_book(target);
			}
			else printf("Book with specified id is not found in collectons\n");
			
			
		}

		else if(strcmp(command, "d") == 0){
			book_id = input("Enter book's id : ");
			target = get_book_bid(atol(book_id), collections);
			if (target != NULL){
				collections = delete_book(target, collections);
			}

			else printf("Book with specified id is not found in collectons\n");
		}

		else if(strcmp(command, "s") == 0){
			print_collections(collections);
		}

		else if(strcmp(command, "aa") == 0){
			member = add_member();
			members = insert_member(member, members);
		}

		else if (strcmp(command, "dd") == 0){
			member_id = input("(delete) Enter member id : ");
			member_target = get_member_bid(atol(member_id), members);
			if (member_target != NULL){
				members = delete_member(member_target, members);
			}
			else printf("Specified target not found in members list\n");
		}

		else if (strcmp(command, "bb") == 0){
			member_id = input("Enter the member id : \n");
			member_target = get_member_bid(atol(member_id), members);
			if (member_target !=  NULL){
				printf("borrowing books for ----->\n");
				print_member(member_target->data, collections);
				while (1){
					book_id = input("Enter book's id to borrow [0 to back] : \n");
					target = get_book_bid(atol(book_id), collections);
					if (target != NULL){
						borrow_book(target, member_target);
						break;
					}
					else if (strcmp(book_id, "0") == 0){
						break;
					}
					printf("Specified book is not found in collections\n");
				}	
			}

			else if (member_target == NULL){
				printf("The specified member is not found in list members\n");
			}
		}

		else if(strcmp(command, "ss") == 0){
			print_members(members, collections);
		}

		else if(strcmp(command, "rb")==0){
			book_id = input("Enter book id for returning : ");
			target = get_book_bid(atol(book_id), collections);
			if (target != NULL){
				member_target = get_member_bid(target->data.borrower, members);
				return_book(&(target)->data, &(member_target)->data);
			}
		}
				

		else if(strcmp(command, "0") == 0){
			while(1){
				command = input("Save collections ? [y/n]");
				if(strcmp(command, "y") == 0){
					save_books(collections);
					save_members(members);
					printf("Data saved\n");
					break;
				}

				else break;
			}
			break;
		}	
	}

	free_nodes(collections);
	free_nodes(members);
	// free_collections(collections);
	// free_members(members);
	return 0;	
}
