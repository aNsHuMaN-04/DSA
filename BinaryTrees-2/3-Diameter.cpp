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


  // Approach - 1: Call a GetHeight function for both right and left at each node and return their sum (max)

  // Approach - 2 : Same concept but without using  function call to another getHeight function
                 // Code is exactly the same of Height with just keeping a diameter variable at each node


                  int solve(TreeNode* root, int& diameter)
    {
        if(root == NULL)
            return 0;
        int lh = solve(root->left, diameter);
        int rh = solve(root->right, diameter);

        diameter = max(diameter , lh + rh);

        return 1 + max(lh, rh);  
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;
        solve(root, diameter);
        return diameter;
    }
