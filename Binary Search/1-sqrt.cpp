#include<bits/stdc++.h>
using namespace std;

    int mySqrt(int x) {
        if (x < 2) return x;

        int low = 1, high = x, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (1LL * mid * mid == x) return mid;
            else if (1LL * mid * mid < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
