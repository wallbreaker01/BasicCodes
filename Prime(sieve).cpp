#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main()
{
    ll n;
    cin>>n;
    vector<ll>v;
    vector<bool>c(n,true);
    for(ll i=2;i*i<=n;i++)
    {
        if(c[i])
        {
            for(ll j=i*i;j<=n;j=j+i)
            {
                c[j]=false;
            }
        }
    }
    for(ll i=2;i<=n;i++)
    {
        if(c[i]) cout<<i<<" ";
    }
    
    
    
}
