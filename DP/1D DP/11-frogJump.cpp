 int solve(int ind, const vector<int>& height, vector<int>& dp) {
        // If at the first stone, cost is 0
        if (ind == 0) return 0;

        // Return memoized result if already computed
        if (dp[ind] != -1) return dp[ind];

        // Initialize jumpTwo with a large value
        int jumpTwo = INT_MAX;

        // Compute cost when jumping from previous stone (ind - 1)
        int jumpOne = solve(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);

        // Compute cost when jumping from two stones back (ind - 2) if possible
        if (ind > 1) {
            jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);
        }

        // Memoize and return the minimum of the two choices
        return dp[ind] = min(jumpOne, jumpTwo);
    }

    // Helper to handle edge cases and start recursion
    int frogJump(const vector<int>& height) {
        // Handle empty input
        if (height.empty()) return 0;

        // Prepare dp with -1 indicating uncomputed states
        int n = (int)height.size();
        vector<int> dp(n, -1);

        // Start from the last index
        return solve(n - 1, height, dp);
    }