// A program to reverse a linked list using recursion
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
struct node * head=NULL;
void reverse (struct node * p){
    if(p->link==NULL){
        head=p;
        return;
    }
    reverse(p->link);
    struct node *q = p->link;
      q->link=p;
      p->link=NULL;
}
///--------------------------------------
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
 ListNode * curr = head, *next, *prev=NULL;
    while(curr!=NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head =  prev;
    return head;
}   
};
///--------------------------------------------------------
void print(struct node * head){
   struct node * h=head;
   while(h!=NULL){
       printf("%d ",h->data);
       h=h->link;
   }
}
void insert(int d){
    struct node * temp=head,*new_add,*temp1;
    new_add=(struct node *)malloc(sizeof(struct node ));
    new_add->link=NULL;
    new_add->data=d;
    if(head==NULL){
        head=new_add;
        return;
    }
    while(temp->link!=NULL)
     temp=temp->link;
     temp->link=new_add;
    
}
int main(){
    int n,x,i;
    printf("How many values you want to enter ? \n");
    scanf(" %d",&n);
    printf("ENter values one by one : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        insert(x);
    }
    printf("Thanks for entering values\n linked list contains : ");
     print(head);
    printf("reverse linked list values : ");
    reverse(head);
    print(head);
    return 0; 
}