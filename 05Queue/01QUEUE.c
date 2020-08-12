//queue implementation using array 
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int ar[MAX_SIZE];
int front = -1, rear = -1;
void Enqueue(int n){
    if(front==-1&&rear==-1){
        front ++;
        rear++;
        ar[rear]=n;
        return ;
    }
    else {
        rear++;
        ar[rear] = n;

    }
}
void Dequeue(){
    if(front == rear){
    printf("QUEUE is empty\n");
    rear = front = -1;
    return ;}
    front++;
}
int isEmpty(){
    if(front==-1&&rear==-1)
    return 1;
    else return 0;
}
int isFull(){
   if(isEmpty())
    return 0;
   else return 1; 
}
void print(){
    if(front==rear==-1||isEmpty()){
        printf("QUEUE is empty \n ");
        return ;
    }
    for(int i= front;i<=rear;i++){
        printf("%d ",ar[i]);
    }
    printf("\n");
}
void Front(){
    if(isEmpty()){
    printf("QUEUE is empty\n");
    return ;
    }
    printf("%d ",ar[front]);
    printf("\n");

}
int main(){
    Dequeue();
    Enqueue(5);
    print();
    Enqueue(1);
    print();
    Enqueue(1000);
    print();
    Front();
    Dequeue();
    Front();
    print();
    Dequeue();
    print();
    Dequeue();
    print();
    Front();

}