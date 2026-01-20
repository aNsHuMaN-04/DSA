#include <bits/stdc++.h>
using namespace std;

// BFS method 

bool detectBFS(int src, vector<int> adj[], vector<int>& vis) {
    vis[src] = true;

    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = true;
                q.push({it, node});
            }
            
            else if(parent != it) {
                return true;
            }
        }
    }


}





    bool dfs(int node, int parent, vector<int> adj[], vector<int>& visited) {
        
        visited[node] = 1;

        for (int neighbor : adj[node]) {

            if (!visited[neighbor]) {
                if (dfs(neighbor, node, adj, visited))
                    return true;
            }

            else if (neighbor != parent) 
                return true;
            
        }

        return false;
    }

    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }




