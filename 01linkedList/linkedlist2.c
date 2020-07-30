//PROGRAM TO ENTER NUMBERS AT BEGINNING OF LINKED LIST:
#include<stdio.h>
#include<stdlib.h>
struct node {
 int data;
 struct node * link;
};
void print();
void insert(int x);
void insert_begining(int x);
struct node * head,*next_add,*temp;
   
int main(){
    int n,i,j,x,choice=1;
    temp = (struct node *)malloc(sizeof(struct node));
    head = temp;
    printf("HOW MANY NUMBERS YOU WANT TO ENTER IN LINKED LIST : \n");
    scanf("%d",&n);
    printf("Enter %d values one by one :\n",n);
    for(i=0;i<n;i++){
       scanf("%d",&x);
       insert(x);
    }
    printf("Entered values in linked list : \n");
    print();
    while(choice){
    printf("Choose options :\n 1 : Add numbers at the end of linked list\n 2 : Add numbers at beginning \n 0 : Exit \n");
    scanf("%d",&choice);
    if(choice==1)
     {
          printf("HOW MANY NUMBERS YOU WANT TO ENTER IN LINKED LIST : \n");
        scanf("%d",&n);
        printf("Enter %d values one by one :\n",n);
        for(i=0;i<n;i++)
        {
       scanf("%d",&x);
       insert(x);
        }
         printf("Entered values in linked list : \n");
         print();
     }
     else if(choice==2){
         printf("HOW MANY NUMBERS YOU WANT TO ENTER IN LINKED LIST : \n");
        scanf("%d",&n);
        printf("Enter %d values one by one :\n",n);
        for(i=0;i<n;i++)
        {
       scanf("%d",&x);
       insert_begining(x);
        }
         printf("Entered values in linked list : \n");
         print();

     }break;
  }
  printf("ended\n");
    return 0;

}


void print(){
     struct node * ptr;
     ptr=head;
     while(ptr->link!=NULL){
         printf("%d ",ptr->data);
         ptr=ptr->link;
     }
     printf("\n");
 }
void insert(int x){
     temp->data=x;
     next_add = (struct node *)malloc(sizeof(struct node));
     temp->link=next_add;
     temp=next_add;
     temp->link=NULL;
 } 
void insert_begining(int x){
    struct node * temp2;
    temp2 = (struct node *)malloc(sizeof(struct node));
    temp2->data=x;
    temp2->link=head;
    head=temp2;
}