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
  int getHeight(TreeNode *node) {
    if (node == nullptr)
      return 0;
    if (node->right == nullptr && node->left == nullptr)
      return 1;
    int ans = 0;
    if (node->right != nullptr) {
      ans = max(ans, getHeight(node->right));
    }
    if (node->left != nullptr) {
      ans = max(ans, getHeight(node->left));
    }
    return ans + 1;
  }
  void draw(TreeNode *root, int x, int y, int h, vector<vector<string>> &ans) {
    if (root == nullptr)
      return;

    ans[x][y] = to_string(root->val);
    if (h - x - 2 < 0)
      return;
    draw(root->left, x + 1, y - (1 << (h - x - 2)), h, ans);
    draw(root->right, x + 1, y + (1 << (h - x - 2)), h, ans);
  }

public:
  vector<vector<string>> printTree(TreeNode *root) {
    int h = getHeight(root);
    int w = (1 << h) - 1;
    vector<vector<string>> ans(h, vector<string>(w, ""));
    int x = 0;
    int y = (w - 1) / 2;
    draw(root, x, y, h, ans);

    return ans;
  }
};
