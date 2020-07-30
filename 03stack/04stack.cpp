//reverse a linked list using stack
#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
struct node {
  int data;
  struct node * next;
};
struct node * head = NULL;
void reverse(){
    stack <struct node *> s;
    if(head==NULL)
    return;
        else {
      struct node * temp=head;
      while(temp!=NULL){
          s.push(temp);
          temp=temp->next;
      } head = s.top();
      temp = head;
      s.pop();
      while(!s.empty()){
         temp->next = s.top();
         temp = temp->next;
         s.pop();
      }
      temp->next = NULL;
    }

}
void print(){
    struct node * temp = head;
    if(temp==NULL){
        cout<<"LINKED LIST IS EMPTY\n";
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    cout<<endl;
}
void insert(int d){
    struct node * temp = head,* new_add;
    new_add = (struct node *)malloc(sizeof(struct node));
    new_add->next= NULL;
    new_add->data = d;
    if(temp==NULL)
    head= new_add;
    else {
        while(temp->next!=NULL){
            temp = temp ->next;
        }
        temp->next = new_add;
    }
}
int main(){
    print();
    reverse();
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    print();
    reverse();
    print();
    reverse();
    print();
    return 0;
}