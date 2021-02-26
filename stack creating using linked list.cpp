#include<iostream>

using namespace std;
struct node{

    int data;
    node *next;
};
node *top = NULL;
void push(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    if(top == NULL)
    {
        top = temp;
        return;
    }
    temp->next = top;
    top = temp;
}
void pop()
{
    node *temp;
    if(top == NULL)
    {
        cout<<"Error Stack is empty";
        return;
    }
    temp = top;
    top = top->next;
    delete(temp);
}
void print()
{
    node *temp = top;
    cout<<"Stack: ";
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    push(2);
    print();
    push(5);
    print();
    push(10);
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
    pop();
    print();
}
