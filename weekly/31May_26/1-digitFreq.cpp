class Solution {
public:
    int digitFrequencyScore(int n) {
        int freq[10] = {0};

        while (n > 0) {
            int d = n % 10;
            freq[d]++;
            n /= 10;
        }

        int score = 0;
        for (int d = 0; d <= 9; d++) {
            score += d * freq[d];
        }

        return score;
    }
};



//using map and set

class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> freq;
        unordered_set<int> st;
        while(n > 0) {
            int d = n % 10;
            n = n / 10;
            freq[d]++; 
            st.insert(d);
        }
        int score = 0;
        for (auto it = st.begin(); it != st.end(); it++) 
            score += *it * freq[*it];
        return score;
        }
};