int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = max(solve(i - 1, j, s1, s2, dp), solve(i, j - 1, s1, s2, dp));
}

int maxLCS(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return solve(n1 - 1, n2 - 1, s1, s2, dp);
}

// for leetcode

class Solution {
public:
    int solve(int i, int j, const string& text1, const string& text2, vector<vector<int>>& dp) {
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (text1[i] == text2[j])
        return dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2, dp);

    return dp[i][j] = max(solve(i - 1, j, text1, text2, dp), solve(i, j - 1, text1, text2, dp));
}

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(n1 - 1, n2 - 1, text1, text2, dp);
    }
};