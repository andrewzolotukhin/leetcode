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
  bool solve(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr)
      return true;
    if (root1 == nullptr || root2 == nullptr || (root1->val != root2->val))
      return false;

    int ch1 = 0, ch2 = 0;
    if (root1->left != nullptr)
      ch1++;
    if (root1->right != nullptr)
      ch1++;
    if (root2->left != nullptr)
      ch2++;
    if (root2->right != nullptr)
      ch2++;
    if (ch1 != ch2)
      return false;

    return (
        (solve(root1->left, root2->left) || solve(root1->left, root2->right)) &&
        (solve(root1->right, root2->right) ||
         solve(root1->right, root2->left)));
  }

public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    return solve(root1, root2);
  }
};
