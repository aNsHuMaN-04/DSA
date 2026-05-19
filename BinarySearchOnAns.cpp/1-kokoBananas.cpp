class Solution {
public:
    int findMax(vector<int>& piles)
    {
        int maxi = INT_MIN;

        for(int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }

        return maxi;
    }

    long long calcHrs(vector<int>& piles, int perHr) {
        long long hrs = 0;

        for(int i = 0; i < piles.size(); i++) {
            hrs += ceil((double)piles[i] / (double)perHr);
        }

        return hrs;
    }   

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            long long hrs = calcHrs(piles, mid);

            if(hrs <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};