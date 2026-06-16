vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int V, int src) {

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
            int adjNode = it.first;
            int wt = it.second;
            if(d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

// dijstra's using set

 vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
        {
            set<pair<int, int>> st; 

            vector<int> dist(V, 1e9); 

            st.insert({0, S}); 

            dist[S] = 0;

            while(!st.empty()) {
             
                auto it = *(st.begin()); 
                int node = it.second; 
                int dis = it.first; 
                st.erase(it); 

                for(auto it : adj[node]) {
                    int adjNode = it[0];  
                    int edgW = it[1];     
             
                    if(dis + edgW < dist[adjNode]) {
                        
                        if(dist[adjNode] != 1e9) 
                            st.erase({dist[adjNode], adjNode}); 

                        dist[adjNode] = dis + edgW; 

                        st.insert({dist[adjNode], adjNode}); 
                    }
                }
            }

            return dist; 
        }