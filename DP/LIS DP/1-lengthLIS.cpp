int solve(int i, int prev, vector<int>& arr, vector<vector<int>>& dp, int n) {

    if(i == n) return 0;

    if(dp[i][prev + 1] != -1) 
        return dp[i][prev + 1];

    int not_take = 0 + solve(i + 1, prev, arr, dp, n);

    int take = 0;
    if(prev == -1 || arr[i] > arr[prev]) {
        take = 1 + solve(i + 1, i, arr, dp, n);
    }

    return dp[i][prev + 1] = max(take, not_take); // since prev is -1 based indexing, we store it at prev + 1 to avoid negative index
}



int LIS(vector<int> arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // we do n + 1 because prev can be -1 to n-1, so we need to accommodate for that in our dp array
    return solve(0, -1, arr, dp, n); 
}