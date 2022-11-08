#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int lower_bound(vector<ll>v,ll element)
{
    ll low=0,high=v.size()-1,mid;
    while(high-low>1)
    {
        ll mid=(high+low)/2;
        if(v[mid]<element) low=mid+1;
        else high=mid;
    }
    if(v[low]>=element) return low;
    if(v[high]>=element) return high;
    return -1;
}

int upper_bound(vector<ll>v,ll element)
{
    ll low=0,high=v.size()-1,mid;
    while(high-low>1)
    {
        ll mid=(high+low)/2;
        if(v[mid]<=element) low=mid+1;
        else high=mid;
    }
    if(v[low]>element) return low;
    if(v[high]>element) return high;
    return -1;
}

int Binary_search(vector<ll>v,ll element)
{
    ll low=0,high=v.size()-1,mid;
    while(high-low>1)
    {
        ll mid=(high+low)/2;
        if(v[mid]< element) low=mid+1;
        else high=mid;
    }
    if(v[low]==element) return low;
    else if(v[high]==element) return high;
    return -1;

}


int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    ll element;
    cin>>element;
    sort(v.begin(),v.end());
    
    ll lb=lower_bound(v,element);
    cout<<lb<<" "<<v[lb]<<endl;
    ll up=upper_bound(v,element);
    cout<<up<<" "<<v[up]<<endl;
}


