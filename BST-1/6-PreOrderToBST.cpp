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
   
   TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(preorder, index, INT_MAX);
    }


    TreeNode* build(vector<int> preorder, int& index, int upBound)
    {
        if(index == preorder.size() || preorder[index] > upBound)
            return NULL;

        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = build(preorder, index, root->val);
        root->right = build(preorder, index, upBound);

        return root;
    }