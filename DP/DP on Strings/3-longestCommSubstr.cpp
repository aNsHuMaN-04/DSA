// here tabulation is better tho 
// memization
class Solution {
public:
    int maxi = 0;

    int solve(int i, int j,
              const string& s1,
              const string& s2,
              vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        solve(i-1, j, s1, s2, dp); // need to explore all states
        solve(i, j-1, s1, s2, dp);

        if(s1[i] == s2[j]) // can't check this first else we won't have the answer
        {
            dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);
            maxi = max(maxi, dp[i][j]);
        }
        else
        {
            dp[i][j] = 0;
        }

        return dp[i][j];
    }

    int longestCommonSubstr(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        solve(n-1, m-1, s1, s2, dp);

        return maxi;
    }
};


// tabulation

int longestCommonSubstr(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    int ans = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}