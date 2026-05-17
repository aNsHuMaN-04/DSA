using namespace std;
# include <bits/stdc++.h>
// here the pivot element is the smallest element in the array. We can use binary search to find the pivot element in O(log n) time. The idea is to compare the middle element with the last element of the array. If the middle element is greater than the last element, then the pivot must be in the right half of the array. Otherwise, it must be in the left half of the array. We can repeat this process until we find the pivot element.
int findPivot(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low < high) // don't use <= because we want to stop when low and high are the same
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high]) {
            low = mid + 1; // since mid is greater than high,  the pivot must be in the right half and -1 cuz it can'tbe mid itself cuz mid is smaller than high
        } else {
            high = mid;
        }
    }

    return low; // or high, both are the same at this point
}

// At any given point either left half or right half is sorted. We can check which half is sorted and then decide whether to search in the left half or the right half based on the target value. This way, we can find the pivot in O(log n) time.

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

// this also tells how many times the array has been rotated
