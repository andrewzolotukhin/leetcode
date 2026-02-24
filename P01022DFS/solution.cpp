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
public:
  void solve(TreeNode *root, int &ans, int val = 0) {
    val = (val << 1) + root->val;
    if (root->left == nullptr && root->right == nullptr) {
      ans += val;
      return;
    }

    if (root->left != nullptr) {
      solve(root->left, ans, val);
    }
    if (root->right != nullptr) {
      solve(root->right, ans, val);
    }
  }
  int sumRootToLeaf(TreeNode *root) {
    int ans = 0;
    solve(root, ans);
    return ans;
  }
};
