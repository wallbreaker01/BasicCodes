#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pb push_back
const ll INF=1e9+10;


int main()
{
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    for (ll i = 0 ; i < m ; i++) 
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edges.pb({u,v,w});
    }
    ll src;
    cin>>src;
    vector<ll>dist(n,INF);
    dist[src]=0;
    for (ll i = 0 ; i < n-1 ; i++) 
    {
        for(auto e : edges)
        {
            ll u = e[0];
            ll v = e[1];
            ll w = e[2];
            dist[v]=min(dist[v],w+dist[u]);
        }
    }
    for (auto i : dist) 
    {
        cout<<i<<" ";
    }
    cout<<endl;





}