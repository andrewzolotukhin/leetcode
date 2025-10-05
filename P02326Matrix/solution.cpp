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
class Solution {
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
    vector<vector<int>> ans(m, vector<int>(n, -1));
    int p = 0;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d = 0, x = 0, y = -1;
    while (head != nullptr && p < m * n) {
      int nx = x + dirs[d].first;
      int ny = y + dirs[d].second;

      if (nx < 0 || nx >= m || ny < 0 || ny >= n || ans[nx][ny] != -1) {
        d++;
        if (d > 3)
          d = 0;
        continue;
      }

      ans[nx][ny] = head->val;
      x = nx;
      y = ny;
      p++;
      head = head->next;
    }

    return ans;
  }
};
