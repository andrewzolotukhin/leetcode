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
  TreeNode *constructFromPrePost(vector<int> &preorder,
                                 vector<int> &postorder) {
    int numOfNodes = preorder.size();
    return constructTree(0, numOfNodes - 1, 0, preorder, postorder);
  }

private:
  TreeNode *constructTree(int start, int end, int ps, vector<int> &preorder,
                          vector<int> &postorder) {
    if (start > end)
      return nullptr;

    if (start == end) {
      return new TreeNode(preorder[start]);
    }

    int leftTree = preorder[start + 1];

    int leftTreeNodes = 1;
    while (postorder[ps + leftTreeNodes - 1] != leftTree) {
      leftTreeNodes++;
    }

    TreeNode *tree = new TreeNode(preorder[start]);

    tree->left = constructTree(start + 1, start + leftTreeNodes, ps, preorder,
                               postorder);

    tree->right = constructTree(start + leftTreeNodes + 1, end,
                                ps + leftTreeNodes, preorder, postorder);

    return tree;
  }
};
