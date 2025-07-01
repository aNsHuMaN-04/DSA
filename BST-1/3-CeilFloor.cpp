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

// Iterative 

int ceilBST(TreeNode* root, int key)
{
    int ceil = INT_MIN;

    while(root != NULL)
    {
        if(root->val == key)
            {
                ceil = root->val;
                return ceil; 
            }
    
            if(key > root->val)
                root = root->right;
            else
            {
                ceil = root->val;
                root = root->left;
            }
        }

        return ceil;
}

// Recursive

int ceilBST(TreeNode* root, int key) {
    if (root == NULL)
        return INT_MIN;

    if (root->val == key)
        return root->val;

    if (key > root->val) {
        // Look in right subtree
        return ceilBST(root->right, key);
    } else {
        // Look in left subtree
        int ceil = ceilBST(root->left, key);
        if (ceil != INT_MIN && ceil >= key)
            return ceil;
        else
            return root->val;
    }
}
