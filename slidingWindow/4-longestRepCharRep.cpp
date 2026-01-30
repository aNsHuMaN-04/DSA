// Intuition - Naive 

int characterReplacement(string s, int k) {
    int maxLen = 0;
    for(int i = 0; i < s.length(); i++) {
        int hash[26] = {0};
        int replaced = 0;
        for(int j = i; j < s.length(); j++) {
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            changes = (j - i + 1) - maxFreq; // Window Size - Frequency ofthe most frequent character in that window
           
            if(changes <= k) 
                maxLen = max(maxLen, j - i + 1);
            else 
                break;
    }
    return maxLen;
}

}
    
    
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ans = 0;

        for(char c = 'A'; c <= 'Z'; c ++) {
            int l = 0, r = 0, replaced = 0;
            while(r < n) {
                if(s[r] == c)
                    r ++;
                else if(replaced < k)   {
                    r ++;
                    replaced ++;
                }
                else if(s[l] == c)
                    l ++;
                else {
                    l ++;
                    replaced --;
                }
                ans = max(ans, r - l);
            }
        } 
        return ans;
    }


    class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0, right = 0;
        int maxFreq = 0, answer = 0;

        vector<int> freq(26, 0);

        while (right < n) {
            // include current character in window
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // if replacements needed > k, shrink window
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // update maximum valid window size
            answer = max(answer, right - left + 1);
            right++;
        }

        return answer;
    }
};
