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
  void solve(TreeNode *root, string s, vector<string> &ans) {
    if (root == nullptr) {
      return;
    }
    if (s != "") {
      s += "->";
    }
    s += to_string(root->val);
    if (root->left == nullptr && root->right == nullptr) {
      ans.push_back(s);
      return;
    }
    solve(root->left, s, ans);
    solve(root->right, s, ans);
  }

public:
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    string s = "";

    solve(root, s, ans);
    return ans;
  }
};
