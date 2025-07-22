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
  void solve(TreeNode *root, int depth, int &ans) {
    if (root == nullptr)
      return;

    if (root->left == nullptr && root->right == nullptr) {
      ans = min(ans, depth);
    }

    solve(root->left, depth + 1, ans);
    solve(root->right, depth + 1, ans);
  }

public:
  int minDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int ans = INT_MAX;
    solve(root, 1, ans);
    return ans;
  }
};
