#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll N = 1e5 + 10;
const ll INF = 1e9 + 10;  // Define a large value for infinity

vector<pair<ll, ll>> g[N]; // Adjacency list for graph with weights
vector<ll> cost(N, INF);   // Cost array to store the minimum cost to each node

// Uniform Cost Search function
void ucs(ll source) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, source});  // Push the source node with cost 0
    cost[source] = 0;

    while (!pq.empty()) {
        auto [curCost, curNode] = pq.top();
        pq.pop();

        if (curCost > cost[curNode]) continue;

        cout << "Node: " << curNode << " with current cost: " << curCost << endl;

        for (auto [child, weight] : g[curNode]) {
            if (curCost + weight < cost[child]) {
                cost[child] = curCost + weight;
                pq.push({cost[child], child});
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;  // Input number of nodes and edges

    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w}); // Assuming undirected graph
    }

    ll source;
    cout << "Enter the source node: ";
    cin >> source;
    ucs(source);

    cout << "\nMinimum costs from source node " << source << ":\n";
    for (ll i = 1; i <= n; i++) {
        cout << "Node " << i << ": ";
        if (cost[i] == INF) {
            cout << "Unreachable" << endl;
        } else {
            cout << cost[i] << endl;
        }
    }
    return 0;
}
