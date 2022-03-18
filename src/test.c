#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEXT 40


typedef struct  Book
{
    char* name;
    int year;
} Book;


typedef struct Node {
    Book data;
    struct Node* next;
}Node;


Node* insert(Book data, Node* head){
    Node* temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

void delete(Node** head, int n){
    Node* temp1 = *head;
	if (n==1){
        temp1 = temp1->next;
    }

    Node* temp2 = *head;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    free(temp1);
    return;

}



void insertoke(Node **head, Book data)
{
    Node *new_node = malloc(sizeof(Node));

    if(!new_node)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;

    Node *temp = *head;

    if(!temp)
        *head = new_node;
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return ;
}

Node* delete_first_node(Node* head){
    Node* temp = head;
    head = temp->next;    
    free(temp);
    return head;
}

void delete_first_nodev(Node* head){
    Node** temp  =&head;
    head  = (*temp)->next;
    free(temp);
    
}

typedef struct Data{
    char *a;
    int b;
}Data;

int main(){
    Data data = {"data", 1};    
    FILE *f = fopen("test.bin", "wb");
    fwrite(&(data), sizeof(data),1,f);
    fclose(f);

    FILE *fr = fopen("test.bin","rb");
    Data dataRead;
    fscanf(fr, " %s %d", dataRead.a, &(dataRead.b));
    printf("data read : %s %d", dataRead.a, dataRead.b);
    fclose(fr);   
}