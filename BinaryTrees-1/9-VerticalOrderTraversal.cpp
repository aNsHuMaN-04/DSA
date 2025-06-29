#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<pair<int, int>, TreeNode*>> todo;

        todo.push({{0, 0}, root});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();

            int x = p.first.first;   // vertical
            int y = p.first.second;  // level
            TreeNode* node = p.second;

            nodes[x][y].insert(node->val);

            if (node->left) {
                todo.push({{x - 1, y + 1}, node->left});
            }

            if (node->right) {
                todo.push({{x + 1, y + 1}, node->right});
            }
        }

        vector<vector<int>> ans;
        for (auto& vertical : nodes) {
            vector<int> col;
            for (auto& level : vertical.second) {
                col.insert(col.end(), level.second.begin(), level.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }