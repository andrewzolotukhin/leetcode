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
  void pass(TreeNode *node, vector<int> &res) {
    if (node == nullptr)
      return;
    if (node->left != nullptr) {
      pass(node->left, res);
    }
    if (node->right != nullptr) {
      pass(node->right, res);
    }
    if (node->left == nullptr && node->right == nullptr) {
      res.push_back(node->val);
      return;
    }
  }

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> t1, t2;
    pass(root1, t1);
    pass(root2, t2);

    if (t1.size() != t2.size())
      return false;

    for (int i = 0; i < t1.size(); i++) {
      if (t1[i] != t2[i])
        return false;
    }
    return true;
  }
};
