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
public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    map<int, TreeNode *> m;
    map<TreeNode *, TreeNode *> p;

    for (auto d : descriptions) {
      int val = d[0];

      TreeNode *curr;
      if (!m.count(val)) {
        m[val] = new TreeNode(val);
      }
    }

    for (auto d : descriptions) {
      int val = d[0], ch = d[1], isLeft = d[2];
      if (!m.count(val))
        m[val] = new TreeNode(val);
      if (!m.count(ch))
        m[ch] = new TreeNode(ch);
      auto self = m[val];
      auto child = m[ch];

      p[child] = self;

      if (isLeft == 1) {
        self->left = child;
      } else {
        self->right = child;
      }
    }

    auto curr = m[descriptions[0][0]];

    while (p[curr] != nullptr) {
      curr = p[curr];
    }

    return curr;
  }
};
