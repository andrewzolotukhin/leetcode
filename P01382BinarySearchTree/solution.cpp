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
  void traverse(TreeNode *node, vector<int> &ans) {
    if (node == nullptr)
      return;
    traverse(node->left, ans);
    ans.push_back(node->val);
    traverse(node->right, ans);
  }
  TreeNode *solve(vector<int> &arr, int l, int r) {
    if (l > r)
      return nullptr;
    int mid = (l + r) / 2;
    auto node = new TreeNode(arr[mid]);
    if (l == r)
      return node;

    if (l + 1 == r) {
      node->right = new TreeNode(arr[mid + 1]);
      return node;
    }

    node->left = solve(arr, l, mid - 1);
    node->right = solve(arr, mid + 1, r);

    return node;
  }

public:
  TreeNode *balanceBST(TreeNode *root) {
    vector<int> arr;

    traverse(root, arr);
    return solve(arr, 0, arr.size() - 1);
  }
};
