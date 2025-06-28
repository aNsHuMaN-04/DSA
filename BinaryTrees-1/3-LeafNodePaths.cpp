#include<bits/stdc++.h>
using namespace std;
 
// Definition for a binary tree node.
 
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    void solve(TreeNode* root, string ds, vector<string>& ans) {
        if (root == NULL) return;

        if (!ds.empty()) {
            ds += "->";
        }
        ds += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(ds);
            return;
        }

        solve(root->left, ds, ans);
        solve(root->right, ds, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }
