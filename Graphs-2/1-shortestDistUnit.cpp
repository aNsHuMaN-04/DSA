// Shortest Distance to all nodes via source node in an undirected unit weight graph
#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>& adj, int V, int src) {

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while(!q.empty)
    {
        int node = q.front();
        q.pop();
        
        for(auto it : adj[node]) {
            if(dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
    
    // The unreachable nodes will have distance as INT_MAX, we can change it to -1 if required

} 