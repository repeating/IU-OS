#include <stdio.h>

struct Node{
    int data;
    struct Node* next;
} *root;

void insert_node(int x)
{
    struct Node* node = root;
    if(root == NULL){
        node->data = x;
        return;
    }
    while(node->next != NULL){
        node = node->next;
    }
    node->next = (struct Node*) malloc(sizeof(struct Node));
    node->next->data = x;
    node->next->next = NULL;
}

void print_list(){
    struct Node* node = root;
    node = node->next;
    while(node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void delete_node(int x){
    x++;
    struct Node* node = root;
    if(node == NULL)
        return;
    if(node->next == NULL)
        root = (struct Node*) malloc(sizeof(struct Node));
    if(node == 0)
        root = node->next;
    for(int i=0;i<x-1 && node->next->next != NULL;i++){
        node = node->next;
    }
    node->next = node->next->next;
}
int main()
{

    root = (struct Node*) malloc(sizeof(struct Node));
    root->next = NULL;
    insert_node(5);
    insert_node(9);
    delete_node(0);
    return 0;
}
