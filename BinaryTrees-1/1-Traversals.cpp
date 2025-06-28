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
 
 
 void inOrderTraversal(TreeNode* root, vector<int>& inorder)
{
    if(root == NULL)
        return;

    inOrderTraversal(root->left, inorder);
    inOrderTraversal(root->right, inorder);
    inorder.push_back(root->val);
}
 
 void preOrderTraversal(TreeNode* root, vector<int>& preorder)
{
    if(root == NULL)
        return;

    preOrderTraversal(root->left, preorder);
    preOrderTraversal(root->right, preorder);
    preorder.push_back(root->val);
}
 void postOrderTraversal(TreeNode* root, vector<int>& postorder)
{
    if(root == NULL)
        return;

    inOrderTraversal(root->left, postorder);
    inOrderTraversal(root->right, postorder);
    postorder.push_back(root->val);
}
 
 
 
 vector<int> Traversal(TreeNode* root) {
        vector<int> inorder;
        vector<int> preorder;
        vector<int> postorder;

        inOrderTraversal(root, inorder);
        preOrderTraversal(root, preorder);
        postOrderTraversal(root, postorder);
        return inorder;
        return preorder;
        return postorder;

    }