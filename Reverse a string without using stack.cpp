#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int i = 0;
    int j = a.length()-1;
    do
    {
        char swap;
        swap = a[i];
        a[i] = a[j];
        a[j] = swap;
        i++;
        j--;
    }while(i!=j);
    cout<<a;
}
