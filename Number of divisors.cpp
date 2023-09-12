#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N=1e7+10;
vector<bool>a(N,true);
vector<int>prime;
vector<bool> p(N, true);


void sieve() 
{
    for(ll i = 2 ; i <= N ; i++)
    {
        if(a[i])
        {
            for(ll j = i*i ; j <= N; j = j+i) a[j]=false;
            prime.push_back(i);
        }
    }
}


ll divisor(ll number)
{
    ll divnum=1;
    for(ll i=2;i*i<=number;i++)
    {
        if(number%i==0)
        {
            ll power=0;
            while(number%i==0)
            {
                power++;
                number/=i;
            }
            divnum*=power+1;
        }
    }
        if (number > 1) divnum *= 2;
    return divnum;
}


ll divisorwithprime(ll number)
{
    sieve();
    ll divnum=1;
    for(ll i=0;i<prime.size() and prime[i]*prime[i]<=number;i++)
    {
        ll power=0;
        while(number%prime[i]==0)
        {
            power++;
            number/=prime[i];
        }
        if(number>1) divnum*=2;
        divnum*=power+1;
    }
    return divnum;
}


int main()
{
    ll n=14;
    cout<<divisorwithprime(n)<<endl;
cout<<divisor(n)<<endl;
}
