//linked list implementation of stack
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * top=NULL;
void push(int d){
   struct node * new_add = (struct node *)malloc(sizeof(struct node));
   new_add->data = d;
   new_add->next = top;
   top = new_add;
}
void pop(){
    struct node * temp;
    temp = top;
    if(temp==NULL){
        printf("STACK IS EMPTY\n");
        return;
    }
    top = top->next;
    free(temp);
}
void print(){
    struct node * temp= top;
    if(temp==NULL)
    {
        printf(" STACK IS EMPTY\n");
        return ;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp ->next;
    }
    printf("\n");
}
void topp(){
    if(top==NULL){
        printf("STACK IS EMPTY\n");
    }
    printf("top = %d\n",top->data);
}
int main(){
    pop();
    push(5);
    push(3);
    push(4);
    push(2);
    push(1);
    print();
    pop();
    print();
    pop();
    print();
    topp();
    pop();
    print();
    pop();
    topp();
    pop();
    pop();
}