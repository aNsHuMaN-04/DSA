class Solution {
public:
    int count = 0;

    void expand(int left, int right, string& s)
    {
        while(left >= 0 &&
              right < s.size() &&
              s[left] == s[right])
        {
            count++;

            left--;
            right++;
        }
    }

    int countSubstrings(string s) {

        for(int i = 0; i < s.size(); i++)
        {
            expand(i, i, s);       // odd length palindromes
            expand(i, i + 1, s);   // even length palindromes
        }

        return count;
    }
};

// dp solution

class Solution {
public:

    bool isPal(int i, int j,
               string& s,
               vector<vector<int>>& dp)
    {
        if(i >= j)
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] != s[j])
            return dp[i][j] = false;

        return dp[i][j] =
            isPal(i+1, j-1, s, dp);
    }

    int countSubstrings(string s) {

        int n = s.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPal(i,j,s,dp))
                    ans++;
            }
        }

        return ans;
    }
};