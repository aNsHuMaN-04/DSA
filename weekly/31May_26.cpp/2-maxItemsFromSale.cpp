class Solution {
public:
    vector<vector<int>> dp;
    vector<int> freeFromItem;
    vector<vector<int>> items;
    int n;

    int solve(int idx, int budget) {
        if (idx == n || budget <= 0) return 0;
        if (dp[idx][budget] != -1) return dp[idx][budget];

        int price = items[idx][1];
        int best = solve(idx + 1, budget); // skip

        for (int copies = 1; copies * price <= budget; copies++) {
            int total = copies + freeFromItem[idx] + solve(idx + 1, budget - copies * price);
            best = max(best, total);
        }

        return dp[idx][budget] = best;
    }

    int maximumSaleItems(vector<vector<int>>& items_, int budget) {
        items = items_;
        n = items.size();

        freeFromItem.assign(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && items[j][0] % items[i][0] == 0)
                    freeFromItem[i]++;

        dp.assign(n, vector<int>(budget + 1, -1));
        return solve(0, budget);
    }
};


// but since we'll always end up buying most copies of the one with least price when we reach end then we should just do this instead in base case

class Solution {
public:
    vector<vector<int>> dp;
    vector<int> freeFromItem;
    vector<vector<int>> items;
    int n;

    int solve(int idx, int budget, int minPrice) {
        if (idx == n || budget <= 0) return budget / minPrice; // spend all remaining on cheapest
        if (dp[idx][budget] != -1) return dp[idx][budget];

        int price = items[idx][1];

        // Option 1: skip
        int best = solve(idx + 1, budget, minPrice);

        // Option 2: buy exactly 1 copy (free copies only trigger once per item type)
        // extra copies of THIS item are handled at base case via minPrice
        if (price <= budget) {
            int total = 1 + freeFromItem[idx] + solve(idx + 1, budget - price, min(minPrice, price));
            best = max(best, total);
        }

        return dp[idx][budget] = best;
    }

    int maximumSaleItems(vector<vector<int>>& items_, int budget) {
        items = items_;
        n = items.size();

        freeFromItem.assign(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && items[j][0] % items[i][0] == 0)
                    freeFromItem[i]++;

        dp.assign(n, vector<int>(budget + 1, -1));

        int minPrice = INT_MAX;
        for (auto& item : items) minPrice = min(minPrice, item[1]);

        return solve(0, budget, minPrice);
    }
};