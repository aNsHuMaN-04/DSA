/* Approach : 1
1 + solve(i + 1, j) : Insert a copy of s[i] on the right side so that s[i] gets a matching partner.
1 + solve(i, j - 1) : Insert a copy of s[j] on the left side so that s[j] gets a matching partner.
https://chatgpt.com/share/6a24199f-a44c-83ec-b264-b99900e806e8
*/

class Solution {
public:
    int solve(int i, int j, string &s, vector<vector<int>> &dp) {
        if(i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = solve(i + 1, j - 1, s, dp);

        return dp[i][j] = 1 + min(solve(i + 1, j, s, dp), solve(i, j - 1, s, dp));
    }

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, s, dp);
    }
};

// Approach 2 : say length of longest palindromic subsequence is lps, then we need to insert (n - lps) characters to make the string a palindrome.

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

    int minInsertions(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int lps = solve(n-1, n-1, s, rev, dp);

        return n - lps;
    }
};