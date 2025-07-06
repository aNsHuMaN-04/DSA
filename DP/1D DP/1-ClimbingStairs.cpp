#include<bits/stdc++.h>
using namespace std;

// Memoization

int solve(int n, vector<int>& dp) {
        // Base cases
        if (n == 0) return 1;
        if (n == 1) return 1; // 1 way to climb 0 steps (do nothing)
        if (n < 0) return 0;  // No way to climb negative steps

        // If already computed, return the result
        if (dp[n] != -1) return dp[n];

        // Recursive calls: taking 1 step and 2 steps
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1); // Initialize memoization array with -1
        return solve(n, dp);       // Call the recursive function
    }



// Tabulation 

    int climbStairs(int n) {
    vector<int> dp(n + 1, 0);

    dp[0] = 1;  // 1 way to climb 0 steps (do nothing)
    dp[1] = 1;  // 1 way to climb 1 step

    for (int i = 2; i <= n; i++) 
        dp[i] = dp[i - 1] + dp[i - 2];
    

    return dp[n];
}


// Min Cost variation


// Memoization

int solve(int n, vector<int>& cost, vector<int>& dp) {
    if (n == 0) return cost[0];
    if (n == 1) return cost[1];
    if (dp[n] != -1) return dp[n];
    dp[n] = cost[n] + min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));
    return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    return min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));
}

// Tabulation 

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}
