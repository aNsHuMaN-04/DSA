 #include <bits/stdc++.h>
 using namespace std;
 
 void markBorderConnected(int r, int c,
                            vector<vector<int>>& borderConnected,
                            vector<vector<char>>& board,
                            int n, int m,
                            int dr[], int dc[])
    {
        borderConnected[r][c] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !borderConnected[nr][nc] && board[nr][nc] == 'O')
            {
                markBorderConnected(nr, nc, borderConnected, board, n, m, dr, dc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        if (m == 0) return;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        vector<vector<int>> borderConnected(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            if (!borderConnected[0][j] && board[0][j] == 'O')
                markBorderConnected(0, j, borderConnected, board, n, m, dr, dc);

            if (!borderConnected[n-1][j] && board[n-1][j] == 'O')
                markBorderConnected(n-1, j, borderConnected, board, n, m, dr, dc);
        }

        for (int i = 0; i < n; i++) {
            if (!borderConnected[i][0] && board[i][0] == 'O')
                markBorderConnected(i, 0, borderConnected, board, n, m, dr, dc);

            if (!borderConnected[i][m-1] && board[i][m-1] == 'O')
                markBorderConnected(i, m-1, borderConnected, board, n, m, dr, dc);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !borderConnected[i][j])
                    board[i][j] = 'X';
            }
        }
    }