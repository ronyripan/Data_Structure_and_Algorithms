#include<iostream>

using namespace std;
struct node
{
    int data;
    node *next;
};
node *front = NULL;
node *rear = NULL;
void enqueue(int x)
{
    node *temp = new node;
    temp->data = x;
    temp->next = NULL;
    if(front == NULL)
    {
        front = temp;
        rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void dequeue()
{
    node *temp = front;
    if(front == NULL)
    {
        cout<<"The queue is empty"<<endl;
        return;
    }
    else if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
    }
    delete(temp);
}
void print()
{
    if(front == NULL)
    {
        cout<<"The queue is empty"<<endl;
        return;
    }
    node *temp = front;
    cout<<"THe queue is: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    enqueue(1);
    enqueue(2);
    print();
    enqueue(3);
    print();
    dequeue();
    print();
    enqueue(5);
    print();
    dequeue();
    print();
    dequeue();
    print();
    dequeue();
    print();
    dequeue();
    print();
}
