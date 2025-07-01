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
    
    
    
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }

    bool solve(TreeNode* root, long mini, long maxi)
    {
        if(root == NULL)
            return true;
        
        if(root->val <= mini || root->val >= maxi)
            return false;

        return solve(root->left, mini, root->val) && solve(root->right, root->val, maxi);
    }


    // Using LONG cuz Leetcode variant has values near INT_MIN and INT_MAX