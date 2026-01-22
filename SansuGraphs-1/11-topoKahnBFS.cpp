#include <bits/stdc++.h>
using namespace std;
 
 vector<int> topologicalSort(int V, vector<vector<int>> adj) {
    
        vector<int> indegree(V, 0);
        
       
        for (int i = 0; i < V; i++) {
            
            for (auto it : adj[i]) {
              
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
       
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while (!q.empty()) {
        
            
            int node = q.front();
            q.pop();
            
            
            topo.push_back(node);
            
            
            for (auto it : adj[node]) {
                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return topo;
    }


    // Using Kahn Algo to check if a cycle is present in Directed Graph

    bool isCyclic(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        count++;

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    return count != V;
}
