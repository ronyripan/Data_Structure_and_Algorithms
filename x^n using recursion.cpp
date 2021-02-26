#include<iostream>
#define ll long long
using namespace std;
ll pow(ll x, ll n)
{
    if(n == 0)
        return 1;
    return x * pow(x,n-1);
}

int main()
{
    ll n,x;
    cin>>x>>n;
    cout<<pow(x,n);

}
