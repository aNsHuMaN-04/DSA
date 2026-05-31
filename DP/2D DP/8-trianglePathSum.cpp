#include <bits/stdc++.h>
using namespace std;
// in this we won't move from n-1, we will move from 0 to n-1, and we will move down and diagonal 
// because last row will have multiple start points and that'll be messy and it's easier to start from one pt and explore
// Class to solve the problem
class Solution {
public:
    // Recursive function with memoization
    int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp) {
        // If value already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // If at bottom row
        if (i == n - 1)
            return triangle[i][j];

        // Compute both downward and diagonal moves
        int down = triangle[i][j] + solve(i + 1, j, triangle, n, dp);
        int diag = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);

        // Store and return min path sum
        return dp[i][j] = min(down, diag);
    }

    // Function to start the process
    int minimumPathSum(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, n, dp);
    }
};



// for leetcode

class Solution {
public:
    int f(vector<vector<int>>& triangle, int row, int col,
          vector<vector<int>>& dp) {

        // Invalid state
        if(col < 0 || col > row)
            return INT_MAX / 2;

        // Reached top
        if(row == 0 && col == 0)
            return triangle[0][0];

        // Already computed
        if(dp[row][col] != -1)
            return dp[row][col];

        // Recursive calls
        int left = triangle[row][col] +
                   f(triangle, row - 1, col - 1, dp);

        int right = triangle[row][col] +
                    f(triangle, row - 1, col, dp);

        // Store and return answer
        return dp[row][col] = min(left, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int row = triangle.size();
        int col = triangle[row - 1].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));

        int mini = INT_MAX;

        // Start recursion from every last row element
        for(int i = 0; i < col; i++) {
            mini = min(mini,
                       f(triangle, row - 1, i, dp));
        }

        return mini;
    }
};