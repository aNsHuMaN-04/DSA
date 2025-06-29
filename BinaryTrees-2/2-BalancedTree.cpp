 
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

 // Basic Intuition
 bool isBalanced1(TreeNode* root) 
 {
       if (root == NULL)
            return true;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (abs(leftHeight - rightHeight) <= 1 && isBalanced1(root->left) && isBalanced1(root->right)) {
            return true;
        }

        return false;
    }


    int getHeight(TreeNode* root) {
        
            if(root == NULL)
                return 0;

            int left = getHeight(root->left);

            int right = getHeight(root->right);

            return 1 + max(left, right); 
    }

    // Better Approach
     
    bool isBalanced2(TreeNode* root) {
        bool ans;
        int height = solve(root);
        
        if(height == -1)
            ans = false;
        else
            ans = true;
        
        return ans;

    }
    

    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int left = solve(root->left);
        if(left == -1)
            return -1;

        int right = solve(root->right);
        if(right == -1)
            return -1;

        if(abs(left - right) > 1)
            return -1;
            
        return 1 + max(left,right);    
    }
