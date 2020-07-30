//A simple program to reverse a linked list BY itertive method :-)
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node* next;
};
struct node * head=NULL;
struct node * reverse(struct node* head){
    struct node * current,* prev,* next;
    current=head;
    prev=NULL;
    while(current!=NULL){
         next = current->next;
         current->next=prev;
         prev = current;
         current=next;
  }
   head = prev;
   return head;
}
void print(struct node * head){
    struct node * temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
struct node * insert(struct node *head,int d){
    struct node * temp=head,* new_add;
    new_add=(struct node *)malloc(sizeof(struct node ));
    new_add->next=NULL;
    new_add->data=d;
     if(head==NULL){
        head=new_add;
    } else {
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=new_add;
   // printf("data : %d ",new_add->data);
    }
    return head;
}
int main(){
    struct node * head=NULL;
      printf("HOW MANY NUMBERS YOU WANT TO ENTER?\n");
    int n,x;
    scanf("%d",&n);
    printf("Enter number : \n");
    for(int i=0;i<n;i++)
      {
         scanf("%d",&x);
          head = insert(head,x);
      }
      printf("Thanks for entering vlaues\n Values in linked list are :\n");
      print(head);
      printf("Reverse of linked list is : \n");
     head= reverse(head);
     print(head);
     printf("Thanks \n");

  
     return 0;
}