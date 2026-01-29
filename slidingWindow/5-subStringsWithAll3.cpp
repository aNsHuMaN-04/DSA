class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int left = 0;
        unordered_map<char, int> char_count = {{'a', 0}, {'b', 0}, {'c', 0}};
        
        for (int right = 0; right < s.length(); ++right) {
            char_count[s[right]]++;
            
            while (char_count['a'] > 0 && char_count['b'] > 0 && char_count['c'] > 0) {
                count += s.length() - right;
                char_count[s[left]]--;
                left++;
            }
        }
        
        return count;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3] = {-1, -1, -1};
        int count = 0;

        for(int i = 0; i < s.length(); i++) {

            lastSeen[s[i] - 'a'] = i;
        
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
                count += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        }
        return count;
    }
};