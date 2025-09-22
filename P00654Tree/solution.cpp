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
  void solve(vector<int> &nums, int l, int r, TreeNode *node, bool isLeft) {
    if (l < 0 || r >= nums.size())
      return;
    if (l > r)
      return;
    int mv = -1, mi = -1;
    for (int i = l; i <= r; i++) {
      if (nums[i] > mv) {
        mv = nums[i];
        mi = i;
      }
    }
    if (isLeft) {
      node->left = new TreeNode(mv);
    } else {
      node->right = new TreeNode(mv);
    }

    solve(nums, l, mi - 1, isLeft ? node->left : node->right, true);
    solve(nums, mi + 1, r, isLeft ? node->left : node->right, false);
  }

public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    int mv = -1, mi = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > mv) {
        mv = nums[i];
        mi = i;
      }
    }
    auto ans = new TreeNode(mv);
    solve(nums, 0, mi - 1, ans, true);
    solve(nums, mi + 1, nums.size() - 1, ans, false);

    return ans;
  }
};
