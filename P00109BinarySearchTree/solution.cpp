/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  void solve(TreeNode *root, vector<ListNode *> &ln, int l, int r,
             bool isLeft) {
    if (l > r)
      return;
    int mid = (r + l) / 2;

    TreeNode *nr = new TreeNode(ln[mid]->val);
    if (isLeft) {
      root->left = nr;
    } else {
      root->right = nr;
    }
    // if(l == mid) return;
    solve(nr, ln, l, mid - 1, true);
    solve(nr, ln, mid + 1, r, false);
  }

public:
  TreeNode *sortedListToBST(ListNode *head) {
    int size = 0;
    if (!head)
      return nullptr;

    vector<ListNode *> ln;

    auto h = head;
    while (h != nullptr) {
      size++;
      ln.push_back(h);
      h = h->next;
    }

    int mid = (size - 1) / 2;

    TreeNode *nh = new TreeNode(ln[mid]->val);

    solve(nh, ln, 0, mid - 1, true);
    solve(nh, ln, mid + 1, size - 1, false);

    return nh;
  }
};
