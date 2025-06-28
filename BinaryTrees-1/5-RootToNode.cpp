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
 

bool solve(TreeNode* root, vector<int>& ans, int x)
{
    ans.push_back(root->val);

    if(root->val == x)
        return true;

    if(root->left != NULL)
    {
        if(solve(root->left, ans, x))
            return true;
        ans.pop_back();
    }   

    if(root->right != NULL)
    {
     if(solve(root->right, ans, x))
            return true;
        ans.pop_back();
    }

    return false;
}

vector<int> RootToNode(TreeNode* root, int x)
{
vector<int> ans;
solve(root, ans, x);
return ans;
}


// Cleaner Code

bool solve(TreeNode* root, vector<int>& ans, int x) {
    if (root == NULL) 
        return false;
    
    ans.push_back(root->val);

    if (root->val == x) 
        return true;

    if (solve(root->left, ans, x) || solve(root->right, ans, x))
        return true;

    ans.pop_back();
    return false;
}

vector<int> RootToNode(TreeNode* root, int x) {
    vector<int> ans;
    solve(root, ans, x);
    return ans;
}
