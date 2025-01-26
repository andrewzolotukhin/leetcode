#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumInvitations(vector<int> &favorite) {
    int n = favorite.size();

    vector<int> degree(n, 0);

    for (int i = 0; i < n; i++) {
      degree[favorite[i]]++;
    }

    queue<int> queue;
    vector<int> depth(n, 1);

    for (int i = 0; i < n; i++) {
      if (degree[i] == 0) {
        queue.push(i);
      }
    }

    while (!queue.empty()) {
      auto current = queue.front();
      queue.pop();

      auto next = favorite[current];

      depth[next] = max(depth[next], depth[current] + 1);

      degree[next]--;
      if (degree[next] == 0) {
        queue.push(next);
      }
    }

    int result = 0;
    int longestPath = 0;

    for (int i = 0; i < n; i++) {
      if (degree[i] == 0)
        continue;

      int len = 0, current = i;

      while (degree[current] != 0) {
        degree[current] = 0;
        current = favorite[current];
        len++;
      }

      if (len == 2) {
        longestPath += depth[i] + depth[favorite[i]];
      } else {
        result = max(result, len);
      }
    }

    return max(result, longestPath);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<int> favorite(n);
  for (int i = 0; i < n; i++) {
    cin >> favorite[i];
  }

  Solution sol;

  cout << sol.maximumInvitations(favorite) << endl;
}
