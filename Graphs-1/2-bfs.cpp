#include <bits/stdc++.h>
using namespace std;

// Starts BFS from only one given node (start).
// It visits only the nodes reachable from start.
// If the graph is disconnected, nodes in other components will never print

void bfs(int start, vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int it : adj[node]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}

// This is BFS for the entire graph.
// It runs BFS from every node that is still unvisited.
// So it covers all connected components and prints every vertex exactly once.

void bfsTraversal(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            queue<int> q;
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                cout << node << " ";

                for (int it : adj[node]) {
                    if (!visited[it]) {
                        visited[it] = true;
                        q.push(it);
                    }
                }
            }
        }
    }
}