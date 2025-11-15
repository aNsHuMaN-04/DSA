#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int it : adj[node]) {
        if (!visited[it]) {
            dfs(it, adj, visited);
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    adj[0].push_back(1);
    adj[0].push_back(4);
    adj[1].push_back(0);
    adj[1].push_back(4);
    adj[1].push_back(3);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[4].push_back(3);

    vector<bool> visited(V, false);

    cout << "DFS starting from node 0:" << endl;
    dfs(0, adj, visited);

    return 0;
}