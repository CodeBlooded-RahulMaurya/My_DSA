#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * link;
};
void print(struct node * head){
    if(head==NULL)
      return ;
      else {
          printf("%d ",head->data);
          print(head->link);
      }
}
void reverse(struct node * head){
    if(head==NULL)
      return ;
      else {
          reverse(head->link);
          printf("%d ",head->data);
          
      }
}
struct node * insert(struct node *head,int d){
    struct node * temp=head,* new_add;
    new_add=(struct node *)malloc(sizeof(struct node ));
    new_add->link=NULL;
    new_add->data=d;
     if(head==NULL){
        head=new_add;
    } else {
        while(temp->link!=NULL)
        temp=temp->link;
        temp->link=new_add;
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
     reverse(head);
     printf("Thanks \n");

  
     return 0;
}
