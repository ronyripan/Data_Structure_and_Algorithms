#include<bits/stdc++.h>

using namespace std;
int countd = 1;
void tower(int n,char beg,char aux,char end)
{
    countd++;
    if(n==1)
    {
        cout<<countd<<" move "<<beg<<" to "<<end<<endl;
    }
    else
    {
        tower(n-1,beg,end,aux);
        tower(1,beg,aux,end);
        tower(n-1,aux,beg,end);
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<"to solve "<<pow(2*1.0,n*1.0)-1<<" moves"<<endl;
    tower(n,'a','b','c');
}
