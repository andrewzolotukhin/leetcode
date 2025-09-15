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
  pair<int, int> solve(TreeNode *root, int &ans) {
    if (root == nullptr)
      return {0, 0};

    auto l = solve(root->left, ans);
    auto r = solve(root->right, ans);

    auto r1 = l.first + r.first + root->val;
    auto r2 = l.second + r.second + 1;
    if (r1 / r2 == root->val) {
      ans++;
    }
    return {r1, r2};
  }

public:
  int averageOfSubtree(TreeNode *root) {
    int ans = 0;
    solve(root, ans);
    return ans;
  }
};
