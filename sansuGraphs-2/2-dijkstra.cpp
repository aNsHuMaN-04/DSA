vector<int> dijkstra(vector<vector<int>>& adj, int V, int src) {

     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
     
    // this can be rewritten as : 
    // using pii = pair<int,int>;
    // priority_queue<pii, vector<pii>, greater<pii>> pq;

        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});  

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) { 
            int adjNode = it[0];
            int wt = it[1];
            if(d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}