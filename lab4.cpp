#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head = NULL;
void Insert(int data, int n)
{
    node *temp1 = new node;
    temp1->data = data;
    temp1->next = NULL;
    if(n==1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    node * temp2 = head;
    for(int i=0;i<n-2;i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void Delete(int a)
{
    int n,count=1;
        node *temp = head;
     while(temp!=NULL)
    {
        if(temp->data==a)
        {
            n=count;
            break;
        }
        count++;
        temp = temp->next;
    }

    node *temp1 = head;
    if(n==1)
    {
        head = temp1->next;
        delete(temp1);
        return ;
    }
    for(int i=0;i<n-2;i++)
    {
        temp1 = temp1->next;
    }
    node *temp2 = temp1->next;
    temp1->next = temp2 ->next;
    delete(temp2);
}
void Search(int a)
{
    int n,count = 1;
    node *temp = head;
    while(temp!=NULL)
    {
        if(temp->data==a)
        {
            n=count;
            break;
        }
        count++;
        temp = temp->next;
    }
    cout<<a<<" is in "<<n <<"th position"<<endl;
}
void Reverse(node *p)
{
    if(p->next==NULL)
    {
        head = p;
        return;
    }
    Reverse(p->next);
    node *q = p->next;
    q->next = p;
    p->next = NULL;
}
void Print()
{
    node * temp = head;
    cout<<"The list is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    while(1){
    cout<<"1: insert\n2: delete\n3: search\n4: reverse\n5: print\n6: Exit\n       linked list"<<endl;
    int choice;
    cin>>choice;
    switch(choice)
    {
    case 1:
        cout<<"Enter the Data: ";
        int data;
        cin>>data;
        cout<<"Enter the position: ";
        int n;
        cin>>n;
        Insert(data,n);
        break;
    case 2:
        cout<<"Enter the Data: ";
        int a;
        cin>>a;
        Delete(a);
        break;
    case 3:
        cout<<"Enter the Data: ";
        int b;
        cin>>b;
        Search(b);
        break;
    case 4:
        Reverse(head);
        break;
    case 5:
        Print();
        break;
    case 6:
        exit(0);
    }}
}
