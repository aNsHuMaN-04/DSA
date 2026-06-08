class Solution {
public:

    void solve(int i, int sum, int flag, string curr,
               vector<string>& ans, int n, int k) {

        if (i == n) {
            ans.push_back(curr);
            return;
        }

        curr += '0';
        solve(i + 1, sum, 0, curr, ans, n, k);
        curr.pop_back();

        if (flag == 0) {
            if (sum + i <= k) {
                curr += '1';
                solve(i + 1, sum + i, 1, curr, ans, n, k);
            }
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        solve(0, 0, 0, "", ans, n, k);
        return ans;
    }
};