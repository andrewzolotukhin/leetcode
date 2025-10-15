/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
  void solve(TreeNode *root, int minV, int maxV, int &ans) {
    if (root == nullptr) {
      return;
    }

    if (minV != INT_MAX && maxV != INT_MIN) {
      ans = max(ans, abs(maxV - root->val));
      ans = max(ans, abs(minV - root->val));
    }

    if (root->left != nullptr) {
      solve(root->left, min(minV, root->val), max(maxV, root->val), ans);
    }
    if (root->right != nullptr) {
      solve(root->right, min(minV, root->val), max(maxV, root->val), ans);
    }
  }

public:
  int maxAncestorDiff(TreeNode *root) {
    int ans = INT_MIN;
    solve(root, INT_MAX, INT_MIN, ans);
    return ans;
  }
};
