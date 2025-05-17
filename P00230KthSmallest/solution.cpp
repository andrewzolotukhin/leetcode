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
  void tr(TreeNode *t, priority_queue<int, vector<int>, greater<int>> &pq) {
    if (t == nullptr)
      return;
    pq.push(t->val);
    tr(t->left, pq);
    tr(t->right, pq);
  }
  int kthSmallest(TreeNode *root, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    tr(root, pq);
    int s = 0;
    while (++s < k)
      pq.pop();
    return pq.top();
  }
};
