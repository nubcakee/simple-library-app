#include <stdio.h>
#include <stdlib.h>
#include "../headers/book.h"
#include "../headers/insert.h"


#define BOOK_PATH "../data/books.bin"
#define MEMBER_PATH "../data/members.bin"

struct Node* read_book(struct Book book, struct Node* head){
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->data = book;
        new_node->next  = NULL;
        if (head == NULL){
            head = new_node;
            return head;
        }

        else{
            struct Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = new_node;
            return head;
        }
}


struct Node* load_books(){
    struct Node* head;
    head = NULL;
    
    
    struct Book buffer[1]; // !!!!!
    int buff_size;

    FILE *f = fopen(BOOK_PATH, "rb");
    if (f == NULL){
        return NULL;
    }
    size_t objects_read= 1;
    int num = 0;
    fseek(f, 0, SEEK_SET);
    while (objects_read == 1){    
        fseek(f,0, SEEK_CUR);  
        objects_read = fread(&buffer[1], sizeof(struct Book), 1, f);
        num++;  
    }
    
    fclose(f);

    buff_size = num-1;
    struct Book data[buff_size];

    FILE *fr = fopen(BOOK_PATH, "rb");
    if (fr == NULL){
        return NULL;
    }
          
    objects_read = fread(&data, sizeof(struct Book), buff_size, f);  
        

    struct Book book;
    for (int i = 0; i < buff_size;i++){
        book = data[i];   
        head = read_book(book, head);
    }

    return head;
}   

void save_books(struct Node* collections){
    struct Node* obj = collections;
    FILE *f = fopen(BOOK_PATH, "wb");
        while (obj != NULL){
            size_t obj_written = fwrite(&(obj->data), sizeof(struct Book), 1, f);    
            obj  = obj->next;
        }
            
    fclose(f);   
}

struct MemberNode* read_member(struct Member member, struct MemberNode* head){
        struct MemberNode* new_node = malloc(sizeof(struct MemberNode));
        new_node->data = member;
        new_node->next  = NULL;
        if (head == NULL){
            head = new_node;
            return head;
        }

        else{
            struct MemberNode* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }

            temp->next = new_node;
            return head;
        }
}



struct MemberNode* load_members(){
    struct MemberNode* head;
    head = NULL;

    struct Member buffer[1];
    int buff_size;

    FILE *f = fopen(MEMBER_PATH, "rb");
    if (f== NULL) return NULL;

    size_t objects_read =1;
    int num=0;
    while (objects_read == 1){
        fseek(f,0,SEEK_CUR);   
        objects_read = fread(&buffer[1], sizeof(struct Member), 1, f);
        num++;
    }
    
    fclose(f);

    buff_size = num-1;
    struct Member data[buff_size];

    FILE *fr = fopen(MEMBER_PATH, "rb");
    if (fr == NULL) return NULL;

    objects_read = fread(&data, sizeof(struct Member), buff_size, f);

    struct Member member;
    for (int i = 0; i < buff_size;i++){
        member = data[i];   
        head = read_member(member, head);
    }

    return head;
}


void save_members(struct MemberNode* members){
    struct MemberNode* obj = members;
    FILE *f = fopen(MEMBER_PATH, "wb");
    while(obj != NULL){
        size_t obj_written = fwrite(&(obj->data), sizeof(struct Member),1,f);
        obj = obj->next;
    }

    fclose(f);
}



