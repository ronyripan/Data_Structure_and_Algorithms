#include<iostream>
#define ll long long
using namespace std;
ll pow(ll x, ll n)
{
    ll y;
    if(n == 0)
        return 1;
    if(n%2 == 0)
    {
        y = pow(x,n/2);
        return y*y;
    }
    return x * pow(x,n-1);
}

int main()
{
    ll n,x;
    cin>>x>>n;
    cout<<pow(x,n);

}

