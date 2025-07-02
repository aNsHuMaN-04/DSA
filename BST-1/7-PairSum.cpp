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

  // Approach -1 : Map
  
bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        return solve(root, k, mp);
    }

    bool solve(TreeNode* node, int k, unordered_map<int, int>& mp) {
        if (node == NULL) 
            return false;

        if (mp.find(k - node->val) != mp.end())
            return true;

        mp[node->val] = 1;

        return solve(node->left, k, mp) || solve(node->right, k, mp);
    }

    // Approach - 2 : Set (Same as map)
       bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }

    bool dfs(TreeNode* node, int k, unordered_set<int>& seen) {
        if (!node) return false;

        if (seen.count(k - node->val)) return true;

        seen.insert(node->val);

        return dfs(node->left, k, seen) || dfs(node->right, k, seen);
    }

// The above two can be used for normal Binary Tree as Well
// This one is BST specific : inorder + Greedy

    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> vals;
        inorder(root, vals);

        int left = 0, right = vals.size() - 1;
        while (left < right) {
            int sum = vals[left] + vals[right];
            if (sum == k) return true;
            if (sum < k) left++;
            else right--;
        }
        return false;
    }