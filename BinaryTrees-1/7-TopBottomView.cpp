#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> topView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    map<int, int> mpp;               // <distance, node value>
    queue<pair<int, TreeNode*> > q;  // <distance, node>

    q.push({0, root});

    while (!q.empty()) {
        pair<int, TreeNode*> temp = q.front();
        q.pop();

        int line = temp.first;
        TreeNode* node = temp.second;

        if (mpp.find(line) == mpp.end()) {
            mpp[line] = node->val;
        }

        if (node->left != NULL) {
            q.push(make_pair(line - 1, node->left));
        }
        if (node->right != NULL) {
            q.push(make_pair(line + 1, node->right));
        }
    }

    for (auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans;
}



vector<int> bottomView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    map<int, int> mpp;               // <distance, node value>
    queue<pair<int, TreeNode*> > q;  // <distance, node>

    q.push(make_pair(0, root));

    while (!q.empty()) {
        pair<int, TreeNode*> temp = q.front();
        q.pop();

        int line = temp.first;
        TreeNode* node = temp.second;

        // Always update for bottom view
        mpp[line] = node->val;

        if (node->left != NULL) {
            q.push(make_pair(line - 1, node->left));
        }
        if (node->right != NULL) {
            q.push(make_pair(line + 1, node->right));
        }
    }

    for (auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans;
}
