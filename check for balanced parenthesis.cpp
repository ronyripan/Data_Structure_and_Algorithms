#include<iostream>
#include<stack>
#include<string>
using namespace std;
int checkpair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return 1;
	else if(opening == '{' && closing == '}') return 1;
	else if(opening == '[' && closing == ']') return 1;
	return 0;
}
int balancecheking(string a)
{
    int n = a.length();
    stack<char>s;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='('||a[i]=='{'||a[i]=='[')
            {
                s.push(a[i]);
            }
        else if(a[i]==')'||a[i]=='}'||a[i]==']')
        {
            if(s.empty()||checkpair(s.top(),a[i])==0)
            {
                cout<<"dd"<<endl;
                return 0;
            }
            else
            {
                s.pop();
            }
        }
    }
    if(s.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    string a;
    cin>>a;
    if(balancecheking(a)==1)
        cout<<"balanced"<<endl;
    else
        cout<<"Error"<<endl;
}
