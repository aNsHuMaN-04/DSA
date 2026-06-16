    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<vector<pair<int, int>>> adj(n);
        for(auto flight : flights) 
            adj[flight[0]].push_back({flight[1], flight[2]});

        queue<pair<int, int>> q;
        q.push({src, 0});

        vector<int> minCost(n, INT_MAX);
        int stops = 0;

        while(!q.empty() && stops <= k) {
            int size = q.size();

            while(size--) {
                int node = q.front().first;
                int cost = q.front().second; 
                q.pop();

                for(auto it : adj[node])
                {
                    int nextEdge = it.first;
                    int wt = it.second;
                    if(cost + wt < minCost[nextEdge]) {
                        minCost[nextEdge] = cost + wt;
                        q.push({nextEdge, minCost[nextEdge]});
                    }
                }
            }
            stops ++;
        }
    if(minCost[dst] == INT_MAX)
        return -1;
    return minCost[dst];

    }
