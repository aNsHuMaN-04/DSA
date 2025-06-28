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

vector<int> MorrisInorder(TreeNode* root) {

        vector<int> inorder;                            
        TreeNode* cur = root;
        
        while (cur != NULL) {
            // If the current node's left child is NULL
            if (cur->left == NULL)
             {
                // Add the value of the current node to the inorder vector

                inorder.push_back(cur->val);
                // Move to the right child
                cur = cur->right;
            } 
            
            else            // If the left child is not NULL, find the predecessor (rightmost node in the left subtree)
            {      

                TreeNode* prev = cur->left;

                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }
                
                // If the predecessor's right child is NULL, establish a temporary link and move to the left child
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } 
                
                else    //i.e. prev->right == curr 
                        // If the predecessor's right child is already linked, remove the link, add current node to inorder vector,
                        //and move to the right child
                
                {
                    
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        return inorder;
    }