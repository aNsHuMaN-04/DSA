// print one LCS
#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<int>& s1, vector<int>& s2,
          vector<vector<int>>& dp)
{
    if(i < 0 || j < 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);

    return dp[i][j] = max(
        solve(i-1, j, s1, s2, dp),
        solve(i, j-1, s1, s2, dp)
    );
}

int main()
{
    vector<int> s1 = {1,2,3,4,5};
    vector<int> s2 = {2,3,5,6};

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << "LCS Length = "
         << solve(n-1, m-1, s1, s2, dp)
         << "\n";

    vector<int> lcs;

    int i = n - 1;
    int j = m - 1;

    while(i >= 0 && j >= 0)
    {
        if(s1[i] == s2[j])
        {
            lcs.push_back(s1[i]);
            i--;
            j--;
        }
        else
{
    int up = 0;
    int left = 0;

    if(i > 0)
        up = dp[i-1][j];

    if(j > 0)
        left = dp[i][j-1];

    if(up >= left)
        i--;
    else
        j--;
}
    }

    reverse(lcs.begin(), lcs.end());

    cout << "One LCS: ";
    for(int x : lcs)
        cout << x << " ";
}




// print all LCS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solve(int i, int j, string& s1, string& s2,
          vector<vector<int>>& dp)
{
    if(i < 0 || j < 0)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(s1[i] == s2[j])
        return dp[i][j] = 1 + solve(i-1, j-1, s1, s2, dp);

    return dp[i][j] = max(
        solve(i-1, j, s1, s2, dp),
        solve(i, j-1, s1, s2, dp)
    );
}

set<string> allLCS;

void generate(int i, int j,
              string curr,
              string& s1,
              string& s2,
              vector<vector<int>>& dp)
{
    if(i < 0 || j < 0)
    {
        reverse(curr.begin(), curr.end());
        allLCS.insert(curr);
        return;
    }

    if(s1[i] == s2[j])
    {
        generate(i-1, j-1,
                 curr + s1[i],
                 s1, s2, dp);
    }
    else
    {
        int up = (i > 0) ? dp[i-1][j] : 0;
        int left = (j > 0) ? dp[i][j-1] : 0;

        if(up == dp[i][j])
            generate(i-1, j, curr, s1, s2, dp);

        if(left == dp[i][j])
            generate(i, j-1, curr, s1, s2, dp);
    }
}

int main()
{
    string s1 = "abcbdab";
    string s2 = "bdcaba";

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << "LCS Length = "
         << solve(n-1, m-1, s1, s2, dp)
         << "\n";

    generate(n-1, m-1, "", s1, s2, dp);

    cout << "All LCS:\n";

    for(auto& str : allLCS)
        cout << str << "\n";
}