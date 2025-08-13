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
  void solve(TreeNode *root, vector<int> &curr, int sum, int targetSum,
             vector<vector<int>> &ans) {
    if (root == nullptr)
      return;
    if (root->left == nullptr && root->right == nullptr &&
        (root->val) + sum == targetSum) {
      vector<int> item = curr;
      item.push_back(root->val);
      ans.push_back(item);
      return;
    }

    if (root->left != nullptr) {
      curr.push_back(root->val);
      solve(root->left, curr, sum + (root->val), targetSum, ans);
      curr.pop_back();
    }
    if (root->right != nullptr) {
      curr.push_back(root->val);
      solve(root->right, curr, sum + (root->val), targetSum, ans);
      curr.pop_back();
    }
  }

public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> curr;
    solve(root, curr, 0, targetSum, ans);
    return ans;
  }
};
