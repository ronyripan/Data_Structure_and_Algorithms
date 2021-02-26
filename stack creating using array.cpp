#include<iostream>
#define MAX_SIZE 101
using namespace std;

class Stack
{
private:
    int A[MAX_SIZE];
    int top = -1;
public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if(top == MAX_SIZE-1)
        {
            cout<<"Error:Stack overflow"<<endl;
            return;
        }
        A[++top] = x;
    }
    void pop()
    {
        if(top == -1)
        {
            cout<<"Error:No element to pop"<<endl;
            return;
        }
        top--;
    }
    int Top()
    {
        return A[top];
    }
    int isEmpty()
    {
        if(top == -1)
        {
            return 1;
        }
        else
            return 0;
    }
    void print()
    {
        cout<<"Stack:";
        for(int i = top; i>=0;i--)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    Stack s;
    s.push(2);
    s.print();
    s.push(5);
    s.print();
    s.push(10);
    s.print();
    s.pop();
    s.print();
}
