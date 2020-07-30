//Array implementation of stack
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
int arr[MAX_SIZE];
int Top = -1;
void push(int data){
    if(Top==MAX_SIZE-1){
        printf("STack overflow\n");
        return;
    }
    ++Top;
    arr[Top]=data;
    }
void pop(){
    if(Top==-1){
        printf("Stack is empty \n");
        return ;
    }
    Top--;

}
void top(){
     printf("%d\n",arr[Top]);
}        
void print(){
    if(Top==-1){
        printf("STack is empty \n");
        return ;
    }
    printf("Stack : ");
    for(int i=0;i<=Top;i++)
    printf("%d ",arr[i]);
    printf("\n");
}
int isEmpty(){
    if(Top==-1)
     return 1;
     else return 0;
}
int main(){
    int choice,element;
    while(1){
    printf("Choose option :\n 1. To push an element \n 2. To pop an element\n 3. To print elements in stack \n 4. To print the last entered element in stack \n 5. To exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:{ printf("Enter element to push : ");
        scanf("%d",&element);
        push(element);
         break;}
        case 2: pop(); 
        break;
        case 3: print();
        break;
        case 4: top();
        break;
        case 5: return 0;
        default : printf("Wrong entry \n");
        break;
    }
    }
    return 0;
}