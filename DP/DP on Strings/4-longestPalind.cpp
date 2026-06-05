// Approach 1 : Intuitive DP
class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp)
    {
        if(i > j) return 0;
        if(i == j) return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = 2 + solve(i+1, j-1, s, dp);

        return dp[i][j] = max(solve(i+1, j, s, dp), solve(i, j-1, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n-1, s, dp);
    }
};

// Approach 2 : LCS of string and its reverse

class Solution {
public:
    int solve(int i, int j, const string& s1, const string& s2, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);

        return dp[i][j] = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));
    }

    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(n-1, n-1, s, rev, dp);
    }
};