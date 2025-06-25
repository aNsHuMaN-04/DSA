#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& matrix, int target) {
    int n = matrix.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (matrix[mid] == target) return true;
        else if (target > matrix[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}