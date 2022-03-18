#include "../headers/insert.h"

static int book_index;
static int member_index;
struct Node* reverse(struct Node* head){
	struct Node *current, *prev, *next;
	current = head;
	prev = NULL;
	while (current != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

void get_max_id(int *max_ptr, int check){
        int temp = check; 
        if (*max_ptr <= check) temp = check;
        *max_ptr = temp + 1;
}

struct Node* insert_book(struct Book book, struct Node* head){
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->data = book;
        new_node->next = NULL;

        if (head == NULL){
            head  = new_node;
            return head;
        }

        else{
            struct Node* temp = head;
            int max_id = temp->data.id;
            get_max_id(&max_id, temp->data.id);
            while(temp->next != NULL){
                temp = temp->next;
                get_max_id(&max_id, temp->data.id);
            }
            
            struct Book *bpt = &book;
            bpt->id =  max_id;
            new_node->data = *bpt;
            temp->next = new_node;
            return head;
        }        
}

struct Node* get_book_bid(int id, struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        if(temp->data.id == id){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void free_collections(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        free(temp);
        temp = temp->next;
    }
}

char* input(char *text){
    int c;
    int  i = 0;
    char string[MAX_TEXT];
    char* temp;
    printf("%s", text);
    scanf(" %[^\n]",string);
    temp = string;
    return temp;
}

struct Book add_book(){
    struct Book book;
    book_index++;
    book.id = book_index;
    char* text_input;
    text_input = input("**Enter book name : ");
    strcpy(book.name, text_input);
    text_input = input("**Enter book's author : ");
    strcpy(book.author, text_input);
    text_input  = input("**Enter published year : ");
    book.year = atol(text_input);
    book.borrower = 0;
    return book;
}

void edit_book(struct Node* target){
        printf("*Edit book ---> \n");
        print_book(target->data);

        char* text_input;
        text_input = input("Book name : ");
        if (strlen(text_input) != 0){
            strcpy(target->data.name, text_input);
        }

        text_input = input("Author : ");
        if (strlen(text_input) != 0){
            strcpy(target->data.author, text_input);
        }
   
        text_input = input("Year published : ");
        if(strlen(text_input) != 0){
            target->data.year = atol(text_input);
        }        
}

struct Node* delete_book(struct Node* target, struct Node* head){
        struct Node* temp = head;
        if (target->data.borrower  != 0){
            printf("Book was being borrowed by someone else, can't delete the book");
        return head;
	}

        if(target->data.id == temp->data.id){ //if first node is targeted
           free(target);
           return head->next;

        }

        while(temp->next->data.id != target->data.id){
            temp = temp->next;
        }

        temp->next = target->next;
        free(target);
        return head;
}


struct Member add_member(){
    struct Member member;
    member_index++;
    char* text_input;
    member.id = member_index;
    text_input = input("Enter Member name : ");
    strcpy(member.name, text_input);    
    member.t_tjoin = time(NULL);
    member.borrow[0] = 0;
    member.borrow[1] = 0;
    member.borrow[2] = 0;
    return member;

}

struct MemberNode* insert_member(struct Member member, struct MemberNode* head ){
        struct MemberNode* new_node = malloc(sizeof(struct MemberNode));
        new_node->data = member;
        new_node->next = NULL;

        if(head == NULL){
            head = new_node;
            return head;
        }

        else{
            struct MemberNode* temp = head;
            int max_id = temp->data.id;
            get_max_id(&max_id, temp->data.id);
            while(temp->next != NULL){
                temp = temp->next;
                get_max_id(&max_id, temp->data.id);
            }

            struct Member *mpt = &member;
            mpt->id = max_id;
            new_node->data = *mpt;
            temp->next = new_node;
            return head;
        }
        
}

struct MemberNode* get_member_bid(int id, struct MemberNode* head){
    struct MemberNode* temp = head;
    while(temp != NULL){
        if(temp->data.id == id){
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

struct MemberNode* delete_member(struct MemberNode* target, struct MemberNode* head){
    struct MemberNode* prev = head;

    if(prev->data.id == target->data.id){ //first node
        free(target);
        return head->next;
    }

    while(prev->data.id != target->data.id){
        prev = prev->next;
    }

    prev = prev->next;
    free(target);
    return head;

}


void free_members(struct MemberNode* head){
    struct MemberNode* temp = head;
    while(temp != NULL){
        free(temp);
        temp = temp->next;
    }
}

void borrow_book(struct Node* book_target, struct MemberNode* member_target){
    for(int i  = 0; i< BOOKS_LIMIT;i++){
        if (member_target->data.borrow[i] == 0 ){ //if member is eligible
            if (book_target->data.borrower == 0){ //if book is free
                member_target->data.borrow[i] = book_target->data.id;
                book_target->data.borrower = member_target->data.id;
                printf("book borrowed\n");
                return;
            }
            else{
                printf("Specified book was being borrowed by someone else\n");
                return;
            }
        }
        
    }

    printf("The member is not eligible to borrow more book\n");
    return;
}


void return_book(struct Book* book, struct Member* member){
        book->borrower = 0;
        for(int i = 0; i< BOOKS_LIMIT; i++){
            if(member->borrow[i] == book->id){
                member->borrow[i] = 0;
                return;
            }
        }
}

void free_nodes_Node(struct Node* head){
    while(head->next != NULL){
        free(head);
        head = head->next;
    }
    free(head);
};

void free_nodes_Member(struct MemberNode* head){
     while(head->next != NULL){
        free(head);
        head = head->next;
    }
    free(head);
};