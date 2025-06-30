#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    bool isSameTree(TreeNode* p, TreeNode* q) {
         
         if(p == NULL || q == NULL)
            return p == q;
    
        bool l = isSameTree(p->left, q->left);
        bool r = isSameTree(p->right, q->right);

        return (p->val == q->val) && (l) && (r);
    }
