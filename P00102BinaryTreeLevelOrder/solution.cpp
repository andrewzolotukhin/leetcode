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
  int run(TreeNode *root, unordered_map<int, vector<int>> &result, int depth) {
    if (root == NULL)
      return 0;
    if (result.count(depth)) {
      result[depth].push_back(root->val);
    } else {
      vector<int> r;
      r.push_back(root->val);
      result[depth] = r;
    }

    auto l = run(root->left, result, depth + 1);
    auto r = run(root->right, result, depth + 1);

    return max(depth, max(l, r));
  }

public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    unordered_map<int, vector<int>> levels;
    auto d = run(root, levels, 1);

    vector<vector<int>> result;
    for (int i = 1; i <= d; i++) {
      vector<int> level;
      for (auto v : levels[i]) {
        level.push_back(v);
      }
      result.push_back(level);
    }
    return result;
  }
};
