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
  void solve(TreeNode *node, int &s) {
    if (node == nullptr)
      return;

    solve(node->right, s);
    int t = s;
    s += node->val;
    node->val += t;
    solve(node->left, s);
  }

public:
  TreeNode *bstToGst(TreeNode *root) {
    int s = 0;
    solve(root, s);
    return root;
  }
};
