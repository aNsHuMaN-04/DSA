#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> mat, int i, int j, int& maxi)
{
    if(i >= mat.size() || j >= mat[0].size())
        return 0;

    int right = solve(mat, i, j + 1, maxi);
    int diagonal = solve(mat, i + 1, j + 1, maxi);
    int down = solve(mat, i + 1, j, maxi);

    if(mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }

    else
        return 0;
}

int MaxSquare(vector<vector<int>> mat, int n, int m)
{
    int maxi = 0;
    solve(mat, 0, 0, maxi);
    return maxi;


    int maxi = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    solveMem(mat, 0, 0, maxi, dp);
    return maxi;
}

int solveMem(vector<vector<int>> mat, int i, int j, int& maxi, vector<vector<int>>& dp)
{
    if(i >= mat.size() || j >= mat[0].size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int right = solveMem(mat, i, j + 1, maxi, dp);
    int diagonal = solveMem(mat, i + 1, j + 1, maxi, dp);
    int down = solveMem(mat, i + 1, j, maxi, dp);

    if(mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }

    else
        return dp[i][j] = 0;
}
