#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> weight, vector<int> value, int index, int capacity)
{
    if(index == 0)
    {
        if(weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    int include = 0;
    if(weight[index] <= capacity)
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);

    int exclude = 0 + solve(weight, value, index - 1, capacity);

    return max(include, exclude);
}


int KnapSack(vector<int> weight, vector<int> value, int maxWeight)
{
    int n = weight.size();

    return solve(weight, value, n - 1, maxWeight);  

    // Memoization

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solveMem(weight, value, n - 1, maxWeight, dp );

    // Tabulation

    return solveTab(weight , value, maxWeight);
}

// Memoization

int solveMem(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>>& dp)
{
    if(index == 0)
    {
        if(weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if(dp[index][capacity] != -1)
        return dp[index][capacity];

    int include = 0;
    if(weight[index] <= capacity)
        include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);

    int exclude = 0 + solveMem(weight, value, index - 1, capacity, dp);

    dp[index][capacity] =  max(include, exclude);

    return dp[index][capacity];

}

// Tabulation

int solveTab(vector<int> weight, vector<int> value, int capacity)
{
    int n = weight.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // Base case: when index = 0
    for(int w = weight[0]; w <= capacity; w++) {
        dp[0][w] = value[0];
    }

    for(int index = 1; index < n; index++) {
        for(int cap = 0; cap <= capacity; cap++) {

            int include = 0;
            if(weight[index] <= cap)
                include = value[index] + dp[index - 1][cap - weight[index]];

            int exclude = dp[index - 1][cap];

            dp[index][cap] = max(include, exclude);
        }
    }

    return dp[n - 1][capacity];
}
