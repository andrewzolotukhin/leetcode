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
  void Solve(TreeNode *root, priority_queue<int> &q) {
    if (root == nullptr)
      return;
    q.push(root->val);
    Solve(root->left, q);
    Solve(root->right, q);
  }

public:
  int getMinimumDifference(TreeNode *root) {
    int ans = INT_MAX;
    priority_queue<int> q;
    Solve(root, q);
    int last = q.top();
    q.pop();

    while (!q.empty()) {
      int l = q.top();
      q.pop();
      ans = min(ans, abs(last - l));
      last = l;
    }
    return ans;
  }
};
