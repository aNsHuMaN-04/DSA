#include <bits/stdc++.h>
using namespace std;

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