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


  // Ignoring Overflow of indices 

  int widthOfBinaryTree1(TreeNode* root) {

    if (!root) 
        return 0;

    int ans = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) 
    {
        int size = q.size();
        int first = q.front().second;
        int last = first;

        for (int i = 0; i < size; i++) 
        {
            int index = q.front().second;
            TreeNode* node = q.front().first;
            q.pop();

            last = index;

            if (node->left) 
                q.push({node->left, index * 2 + 1});

            if (node->right) 
                q.push({node->right, index * 2 + 2});
        }

        ans = max(ans, (last - first + 1));
    }

    return ans;
}

// To Keep Overflow in check

int widthOfBinaryTree2(TreeNode* root) {

        if (!root) 
            return 0;
    
    int ans = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) 
    {
        int size = q.size();
        int mmin = q.front().second;
        int first, last;

        for (int i = 0; i < size; i++) {

            int index = q.front().second - mmin;
            TreeNode* node = q.front().first;
            q.pop();
            
            if (i == 0)     
                first = index;
            
            if (i == size - 1) 
                last = index;
            
            if (node->left) 
                q.push({node->left, index * 2 + 1});
            
            if (node->right) 
                q.push({node->right, index * 2 + 2});
        }

        ans = max(ans, ((last - first + 1)));
    }
    return ans;
        
    }