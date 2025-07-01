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

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insert(nums, 0, nums.size() - 1);
    }

    TreeNode* insert(vector<int>& nums, int start, int end) 
    {
        if (start > end)
          return NULL;  

        int mid = (start + end) / 2;

        TreeNode* node = new TreeNode(nums[mid]);

        node->left = insert(nums, start, mid - 1);
        node->right = insert(nums, mid + 1, end);

        return node;
    }

