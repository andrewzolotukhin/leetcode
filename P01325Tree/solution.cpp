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
  bool solve(TreeNode *root, int target) {
    if (root == nullptr)
      return true;

    if (root->left == nullptr && root->right == nullptr) {
      return root->val == target;
    }

    if (root->left != nullptr) {
      if (solve(root->left, target)) {
        root->left = nullptr;
      }
    }
    if (root->right != nullptr) {
      if (solve(root->right, target)) {
        root->right = nullptr;
      }
    }

    return (root->left == nullptr && root->right == nullptr &&
            root->val == target);
  }

public:
  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    if (solve(root, target))
      return nullptr;

    return root;
  }
};
