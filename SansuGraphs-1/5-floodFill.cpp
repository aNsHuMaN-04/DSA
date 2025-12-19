using namespace std;
#include <bits/stdc++.h>    

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        int org = image[sr][sc];
        if (org == color) return image;   // important check

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while(!q.empty()) {

            auto [x, y] = q.front();   // take current pixel
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // boundary + same original color
                if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(image[nx][ny] != org) continue;

                image[nx][ny] = color;
                q.push({nx, ny});
            }
        }

        return image;
    }

