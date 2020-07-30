//reverse a string using stack
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
void reverse(char *c,int l){
stack <char> s;
for (size_t i = 0; i < l; i++)
{
    s.push(c[i]);
}
for (size_t i = 0; i < l; i++)
{
    c[i]=s.top();
    s.pop();
}
}
 
int main(){
    char c[1001];
    cout<<"ENTER ANY STRING TO REVERSE : ";
    scanf("%s",&c);
    reverse(c,strlen(c));
    printf("%s\n",c);
    return 0;

}