// approach - 1
int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int res = 0;
        vector<bool> vis(128, false); 

        int left = 0;
        for (int right = 0; right < n; right++) {
     
            while (vis[s[right]]) {
                vis[s[left]] = false;
                left++;
            }
            
  
            vis[s[right]] = true;
            
            res = max(res, right - left + 1);
        }
        return res;
    }

// optimized sliding window
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int maxLen = 0;
        
        vector<int> hash(128, -1); 
        int l = 0, r = 0; 

        while(r < n) {

            if(hash[s[r]] != -1) {
                if(hash[s[r]] >= l) 
                    l = hash[s[r]] + 1;
            }

            hash[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;

        }

        return maxLen;
    }