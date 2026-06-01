#include <cmath>

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        long long left = ceil(pow((double)l, 1.0 / k));
        long long right = floor(pow((double)r, 1.0 / k) + 1e-7);

        return max(0LL, right - left + 1);
    }
};