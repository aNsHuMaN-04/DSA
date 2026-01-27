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
        int res = 0;
        
        vector<int> lastIndex(128, -1); 
        int start = 0; 

        for (int end = 0; end < n; end++) {
            start = max(start, lastIndex[s[end]] + 1);

            res = max(res, end - start + 1);

           
            lastIndex[s[end]] = end;
        }
        return res;
    }