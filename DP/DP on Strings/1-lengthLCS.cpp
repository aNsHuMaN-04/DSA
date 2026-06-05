int solve(int i, int j, vector<int>& s1, vector<int>& s2, vector<vector<int>>& dp) {
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = max(solve(i - 1, j, s1, s2, dp), solve(i, j - 1, s1, s2, dp));
}

int maxLCS(vector<int>& s1, vector<int>& s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return solve(n1 - 1, n2 - 1, s1, s2, dp);
}