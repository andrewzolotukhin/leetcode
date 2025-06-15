class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    stack<int> st;

    for (int i = 0; i < asteroids.size(); i++) {
      if (st.empty() || st.top() * asteroids[i] >= 0) {
        st.push(asteroids[i]);
        continue;
      }

      int prev = st.top();

      if (prev >= 0 && asteroids[i] <= 0 && !(prev == 0 && asteroids[i] == 0)) {
        if (prev == -asteroids[i]) {
          st.pop();
        } else if (prev < -asteroids[i]) {
          st.pop();
          i--;
        }
      } else {
        st.push(asteroids[i]);
      }
    }

    vector<int> ans(st.size());

    int i = st.size() - 1;
    while (!st.empty()) {
      ans[i--] = st.top();
      st.pop();
    }
    return ans;
  }
};
