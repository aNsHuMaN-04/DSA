using namespace std;
# include <bits/stdc++.h>

int findPivot(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low; // or high, both are the same at this point
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int pivotIndex = findPivot(arr);
    cout << "Pivot index: " << pivotIndex << endl; // Output: Pivot index: 4
    return 0;
}

// for linear search
int findPivotLinear(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) {
            return i; // Pivot found at index i
        }
    }
    return 0; // No pivot found, array is not rotated
}