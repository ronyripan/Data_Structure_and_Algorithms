#include<iostream>
#include<stack>
using namespace std;

struct node
{
    int data;
    node *next;
};
 node *head = NULL;
 void create()
 {
     for(int i=1;i<10;i++)
     {
         node *temp = new node;
         temp->data = i;
         temp->next = NULL;
         if(head == NULL)
         {
             head = temp;
         }
         else
         {
             node *temp1 = head;
             while(temp1->next!=NULL)
             {
                 temp1 = temp1->next;
             }
             temp1->next = temp;
         }
     }
 }
 void print()
 {
     node *temp = head;
     while(temp!=NULL)
     {
         cout<<temp->data<<" ";
         temp = temp->next;
     }
     cout<<endl;
 }
 void reverse()
 {
     node *temp = head;
     stack<node *>s;
     while(temp!=NULL)
     {
         s.push(temp);
         temp = temp->next;
     }
     node *temp1 = s.top();
     head = temp1;
     s.pop();
     while(!s.empty())
     {
         temp1->next = s.top();
         s.pop();
         temp1 = temp1->next;
     }
     temp1->next = NULL;
 }
int main()
{
    create();
    print();

    reverse();
    print();
}
