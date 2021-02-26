#include<iostream>

using namespace std;
int head = -1,rear = -1,arr[10]={0};
bool  isEmpty()
{
    if(head == -1&&rear == -1) return true;
    else return false;
}
bool isFull()
{
    if(rear == 10-1) return true;
    else return false;
}
void enqueue(int a)
{
    if((rear+1)%10 == head)
        return;
    else if(isEmpty())
        {
            head = 0;
            rear = 0;
        }
    else
        rear = (rear+1)%10;
    arr[rear] = a;
}
void dequeue()
{
    if(isEmpty())
        cout<<"The queue is empty"<<endl;
    else if(head == rear)
    {
        arr[head] = 0;
        head = -1;
        rear = -1;
    }
    else
    {
        arr[head] = 0;
        head = (head+1)%10;
    }


}
int front()
{
    return arr[head];
}
void print()
{
    if(isEmpty())
    {
        cout<<"The queue is empty"<<endl;
        return;
    }
    for(int i = 0;i <10; i++)
    {
        if(arr[i]!=0)
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int x;
    enqueue(12);
    enqueue(13);
    print();
    dequeue();
    print();
    dequeue();
    print();
    enqueue(12);
    enqueue(13);
    enqueue(12);
    enqueue(13);
    enqueue(12);
    enqueue(13);
    enqueue(12);
    enqueue(13);
    enqueue(12);
    enqueue(13);
    print();
    dequeue();
    print();
    dequeue();
    print();
    enqueue(12);
    enqueue(13);
    print();
}
