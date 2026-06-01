// using set
class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> st;
        for(char ch : password)
            st.insert(ch);
        int strength = 0;
        for (char ch : st) {
            if(ch >= 'a' && ch <= 'z')  strength += 1;
            else if(ch >= 'A' && ch <= 'Z') strength += 2;
            else if(ch >= '0' && ch <= '9') strength += 3;
            else
            strength += 5;
    }
    return strength;
    
    }
};

// using frequency array

class Solution {
public:
    int passwordStrength(string password) {
        bool vis[256] = {false};
        int strength = 0;

        for (char ch : password) {
            if (vis[ch])
                continue;

            vis[ch] = true;

            if (ch >= 'a' && ch <= 'z')
                strength += 1;
            else if (ch >= 'A' && ch <= 'Z')
                strength += 2;
            else if (ch >= '0' && ch <= '9')
                strength += 3;
            else
                strength += 5;
        }

        return strength;
    }
};