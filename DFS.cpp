#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const ll N = 1e5+10;

vector<ll>g[N];
bool vis[N];

void dfs(ll vertex)
{
    cout<<vertex<<endl;
    vis[vertex] = true;    //vertex e dhukar pore kaj
    for( ll child : g[vertex])
    {
        cout<<"P : "<<vertex<<" C : "<<child<<endl;
        if(vis[child]) continue;    //child e dhukar age kaj
        dfs(child);
        //child theke ber howar age

    }
    //vertex e ber howar age

}

int main()
{
    ll n, m;
    cin >> n >> m ;
    for (ll i = 0 ; i < 9 ; i++) 
    {
        ll v1, v2;
        cin >> v1 >> v2 ;
        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }
    dfs(1);
    

    
}