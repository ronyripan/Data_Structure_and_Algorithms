#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *head = NULL;
node *getnewnode(int a)
{
    node *temp = new node;
    temp->data = a;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void inserth(int x)
{
    node *temp = getnewnode(x);
    if(head == NULL)
    {
        head = temp;
        return ;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void insertt(int x)
{
    node *temp = getnewnode(x);
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        node *temp1 = head;
        while(temp1->next != NULL)
            temp1 = temp1->next;
        temp->prev = temp1;
        temp1->next = temp;
    }
}
void print()
{
    node *temp = head;
    cout<<"forwar:";
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void rprint()
{
    node *temp = head;
    if(temp == NULL)
        return;
    while(temp->next != NULL)
        temp = temp->next;
    cout<<"reverse: ";
     while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}
int main()
{
    insertt(2);
    print();
    rprint();
    insertt(3);
    print();
    rprint();
    insertt(4);
    print();
    rprint();
    insertt(5);
    print();
    rprint();
}
