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
 
// Approach - 1 : Use Level Order and for a Particular Level , Display the First or Last 

// Approach -2 : Recursive Approach :

  void solveRightView(TreeNode* root, int level, vector<int>& ansRight)
  {
    if(root == NULL)
        return;
    
    if(ansRight.size() == level)
        ansRight.push_back(root->val);
    
    solveRightView(root->right, level + 1, ansRight);
    solveRightView(root->left, level + 1, ansRight);
  }

  vector<int> RightView(TreeNode* root)
  {
    vector<int> ansRight;
    solveRightView(root, 0, ansRight);
    return ansRight;
  }



 void solveLeftView(TreeNode* root, int level, vector<int>& ansLeft)
  {
    if(root == NULL)
        return;
    
    if(ansLeft.size() == level)
        ansLeft.push_back(root->val);
    
    solveLeftView(root->left, level + 1, ansLeft);
    solveLeftView(root->right, level + 1, ansLeft);
  }

  vector<int> LeftView(TreeNode* root)
  {
    vector<int> ansLeft;
    solveLeftView(root, 0, ansLeft);
    return ansLeft;
  }



