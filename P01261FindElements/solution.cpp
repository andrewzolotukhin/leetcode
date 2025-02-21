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
class FindElements {
private:
  set<long long> elements;
  void dfs(TreeNode *root, int x, bool isLeft) {
    long long val = 2 * x + (isLeft ? 1 : 2);
    elements.insert(val);
    if (root->left) {
      dfs(root->left, val, true);
    }
    if (root->right) {
      dfs(root->right, val, false);
    }
  }

public:
  FindElements(TreeNode *root) {
    elements.insert(0);
    if (root->left) {
      dfs(root->left, 0, true);
    }
    if (root->right) {
      dfs(root->right, 0, false);
    }
  }

  bool find(int target) { return elements.count(target) > 0; }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
