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
  void solve(TreeNode *node, int &ans, int depth, int &maxDepth) {
    if (node == nullptr)
      return;
    if (node->left == nullptr && node->right == nullptr) {
      if (depth > maxDepth) {
        maxDepth = depth;
        ans = 0;
      }
      if (depth == maxDepth) {
        ans += node->val;
      }
      return;
    }
    solve(node->left, ans, depth + 1, maxDepth);
    solve(node->right, ans, depth + 1, maxDepth);
  }

public:
  int deepestLeavesSum(TreeNode *root) {
    int ans = 0;
    int maxDepth = 0;
    solve(root, ans, 0, maxDepth);
    return ans;
  }
};
