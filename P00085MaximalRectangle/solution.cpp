#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int getMaxArea(vector<int> &hist) {
    int n = hist.size();
    stack<pair<int, int>> st;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      int curr = hist[i];
      int index = i;
      while (!st.empty() && st.top().second > curr) {
        int ni = st.top().first;
        ans = max(ans, st.top().second * (i - ni));
        st.pop();
        index = ni;
      }
      st.push({index, curr});
    }

    while (!st.empty()) {
      int ni = st.top().first;
      int nh = st.top().second;
      st.pop();

      ans = max(ans, nh * (n - ni));
    }

    return ans;
  }

public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    int result = 0;

    int n = matrix.size(), m = matrix[0].size();

    vector<int> hist(m, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') {
          hist[j]++;
        } else {
          hist[j] = 0;
        }
      }

      result = max(result, getMaxArea(hist));
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  Solution sol;

  int n;

  cin >> n;

  vector<vector<char>> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<char> v;
    for (char c : s) {
      v.push_back(c);
    }
    m.push_back(v);
  }

  cout << sol.maximalRectangle(m) << '\n';
}
