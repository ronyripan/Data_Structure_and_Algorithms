#include<iostream>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
void reversestring(char a[])
{
    stack<char>s;
    int n;
    n = strlen(a);
    for(int i=0;i<n;i++)
    {
        s.push(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        a[i] = s.top();
        s.pop();
    }
}
int main()
{
    char a[51];
    cout<<"Enter a string: ";
    cin>>a;
    reversestring(a);
    cout<<a;
}
