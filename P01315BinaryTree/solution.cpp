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
  void solve(TreeNode *root, int parent, int grandParent, int &ans) {
    if (root == nullptr)
      return;
    if (grandParent % 2 == 0) {
      ans += root->val;
    }

    if (root->left != nullptr) {
      solve(root->left, root->val, parent, ans);
    }

    if (root->right != nullptr) {
      solve(root->right, root->val, parent, ans);
    }
  }

public:
  int sumEvenGrandparent(TreeNode *root) {
    int ans = 0;

    solve(root, -1, -1, ans);
    return ans;
  }
};
