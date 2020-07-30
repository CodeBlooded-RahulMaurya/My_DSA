//linked list implementation of Queue
#include<stdio.h>
#include<stdlib.h>
//#include<bool.h>
struct node {
    int data;
    struct node * next;
};

struct node * front =NULL, * rear = NULL;

void Enqueue (int d){
 struct node * new_add = (struct node *)malloc(sizeof(struct node));
 new_add->data = d;
 new_add->next = NULL;
 if(front == NULL && rear == NULL){
      front = rear = new_add;
      return ;
 }
 rear ->next = new_add;
 rear = new_add;
}

void Dequeue(){
    if(front==NULL&&rear == NULL){
        printf("Error : Queue is already empty.\n");
        return ;
    }
    struct node * temp  = front;
    front = front ->next;
    free(temp);
}

int isEmpty(){
    if(rear == NULL && front == NULL){
    printf("Queue is Empty.\n");
    return 1;
    }
    else return 0;
}

void Print(){
    if(rear == NULL && front == NULL){
       printf("Error : Queue is Empty. \n");
       return;
    }
    struct node * temp = front;
    printf("Queue : ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp= temp->next;
    }
    printf("\n");
}

int Front(){
    if(front == NULL){
        printf("Error : Queue is Empty.\n");
        return 0;
    }
    printf("Front : %d \n",front->data);
    return front->data;
}

int main(){
     Dequeue();
     Print();
     Enqueue(4);
     Print();
     Front();
     Enqueue(56);
     Dequeue();
     Enqueue(4536);
     Enqueue(89);
     Print();
     Front();
     Enqueue(1);
     Print();
     Enqueue(2);
     Print();
     Enqueue(3);
     Enqueue(4);
     Enqueue(5);
     Print();
    return 0;
}