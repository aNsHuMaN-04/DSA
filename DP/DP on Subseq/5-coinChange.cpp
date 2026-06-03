  // using Take and Not Take and 2D DP 
   int helper(int i, vector<int>& coins, int amount, vector<vector<int>> dp) {

        if(amount == 0)
            return 0;

        if(i < 0)
            return 1e9;

        if(dp[i][amount] != -1)
            return dp[i][amount];

        int notTake = helper(i - 1, coins, amount, dp);

        int take = 1e9;
        if(coins[i] <= amount)
            take = 1 + helper(i, coins, amount - coins[i], dp);

        return dp[i][amount] = min(take, notTake);
    }
// using Loop and 1D DP
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        dp.resize(n, vector<int>(amount + 1, -1));

        int ans = helper(n - 1, coins, amount);

        if(ans >= 1e9)
            return -1;

        return ans;
    }

int helper(vector<int>& coins, int amount, vector<int>& dp) {

        if(amount == 0)
            return 0;

        if(amount < 0)
            return -1;

        if(dp[amount] != -2)
            return dp[amount];

        int mini = INT_MAX;

        for(int coin : coins) {

            int res = helper(coins, amount - coin, dp);

            if(res >= 0)
                mini = min(mini, 1 + res);
        }

        if(mini == INT_MAX)
            return dp[amount] = -1;

        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, -2);

        return helper(coins, amount, dp);
    }