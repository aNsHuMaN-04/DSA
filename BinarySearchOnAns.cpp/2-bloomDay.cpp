class Solution {
public:

    int countBouq(vector<int>& bloomDay, int d, int m, int k) {
        
        int cnt = 0, bouq = 0;
        
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= d) cnt++;
            else {
                bouq += cnt / k;
                cnt = 0;
            }
        }
        
        bouq += cnt / k;
        return bouq;

    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int n = bloomDay.size();
        
        if(1LL * m * k > n) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            mini = min(bloomDay[i], mini);
            maxi = max(bloomDay[i], maxi);
        }

        int low = mini, high = maxi, ans = 0;
       
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(countBouq(bloomDay, mid, m, k) >= m) {
                ans = mid;
                high = mid - 1;
            }
            else
            low = mid + 1;
        }
        return ans;
    }
};