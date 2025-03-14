class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<pair<int, int>> st;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      int h = heights[i];
      int index = i;
      while (!st.empty() && st.top().second > h) {
        int oi = st.top().first;
        int oh = st.top().second;
        st.pop();

        ans = max(ans, oh * (i - oi));
        index = oi;
      }

      st.push({index, h});
    }

    while (!st.empty()) {
      int i = st.top().first;
      int h = st.top().second;
      st.pop();

      ans = max(ans, h * (n - i));
    }

    return ans;
  }
};
