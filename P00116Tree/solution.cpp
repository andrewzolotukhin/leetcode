/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
  void solve(Node *node, Node *next) {
    if (node == nullptr)
      return;
    if (next != nullptr) {
      node->next = next;
    }
    solve(node->left, node->right);
    solve(node->right, (next == nullptr) ? nullptr : next->left);
  }

public:
  Node *connect(Node *root) {
    solve(root, nullptr);
    return root;
  }
};
