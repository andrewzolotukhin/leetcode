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
  void process(TreeNode *node,
               priority_queue<int, vector<int>, greater<>> &pq) {
    if (node == nullptr)
      return;
    process(node->left, pq);
    pq.push(node->val);
    process(node->right, pq);
  }

public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    priority_queue<int, vector<int>, greater<>> pq;
    process(root1, pq);
    process(root2, pq);

    vector<int> ans;
    while (!pq.empty()) {
      ans.push_back(pq.top());
      pq.pop();
    }

    return ans;
  }
};
