#include<bits/stdc++.h>
using namespace std;


int solveMem(vector<int>& coins, int amount, vector<int>& dp)
{
    if(amount == 0)
        return 0;
    if(amount < 0)
        return INT_MAX;

    if(dp[amount] != -1)
        return dp[amount];
    
    int mini = INT_MAX;

    for(int i = 0; i < coins.size(); i++)
    {
        int ans = solveMem(coins, amount - coins[i], dp);

        if(ans != INT_MAX)
            mini = min(mini,1+ans);
    }

    dp[amount] = mini;

    return mini;
}

int minCoins(vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, -1);
    int ans = solveMem(coins, amount, dp);

    if(ans == INT_MAX)
        return -1;
    else
        return ans;
}


// Tabulation


#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;  // 0 coins needed to form amount 0

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) // To check Overflow (INT_MAX + 1)
            { 
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        return -1;
    } else {
        return dp[amount];
    }
}
