 int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        int dr[8] = {-1,-1,-1, 0,0, 1,1,1};
        int dc[8] = {-1, 0, 1,-1,1,-1,0,1};

        dist[0][0] = 1;
        q.push({1, {0, 0}});

        while(!q.empty()) {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            if (r == n-1 && c == n-1) return d;

            for(int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 && d + 1 < dist[nr][nc]) {
                    
                    dist[nr][nc] = d + 1;
                    q.push({d + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }