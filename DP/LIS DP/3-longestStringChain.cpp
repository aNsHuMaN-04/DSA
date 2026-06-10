class Solution {
public:

    bool checkPossible(string& s1, string& s2) {
        if (s1.size() != s2.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == s2.size();
    }

    int solve(int i, int prev, vector<string>& words,
              vector<vector<int>>& dp, int n) {

        if (i == n)
            return 0;

        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int not_take = solve(i + 1, prev, words, dp, n);

        int take = 0;

        if (prev == -1 || checkPossible(words[i], words[prev])) {
            take = 1 + solve(i + 1, i, words, dp, n);
        }

        return dp[i][prev + 1] = max(take, not_take);
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(),
             [](string& a, string& b) {
                 return a.size() < b.size();
             });

        int n = words.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, -1, words, dp, n);
    }
};