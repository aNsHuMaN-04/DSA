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

// Recursive : 
TreeNode* searchBST(TreeNode* root, int val) 
{
        if(root == NULL || root->val == val) 
            return root;

            if(val < root->val) 
                return searchBST(root->left, val);
            else 
                return searchBST(root->right, val);
    }

// Iterative :
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val)
        {
            if(root->val>val) root=root->left;
            else root=root->right;
        }
        return root;
    }