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
  int dfs(TreeNode *node, priority_queue<int> &queue) {
    if (node == nullptr)
      return 0;
    // if(node->left == nullptr || node->right == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) {
      // cout << "pushing " <<  1 << '\n';
      queue.push(1);
      return 1;
    }

    int left = dfs(node->left, queue);
    int right = dfs(node->right, queue);
    if (left == right && left != 0) {
      // cout << "pushing " << left + right + 1 << '\n';
      queue.push(left + right + 1);
      return left + right + 1;
    }
    return 0;
  }

public:
  int kthLargestPerfectSubtree(TreeNode *root, int k) {
    priority_queue<int> queue;
    int r = dfs(root, queue);
    // if(r > 1) {
    //     queue.push(r);
    // }

    int i = 0;
    while (!queue.empty()) {
      if (++i == k) {
        return queue.top();
      }
      queue.pop();
    }

    return -1;
  }
};
