class Solution {
public:
  vector<int> getRow(int rowIndex) {
    stack<int> st1, st2;
    st1.push(1);

    for (int i = 0; i < rowIndex; i++) {
      stack<int> &st = st1.empty() ? st2 : st1;
      stack<int> &t = st1.empty() ? st1 : st2;

      t.push(1);
      int prev = st.top();
      st.pop();
      while (!st.empty()) {
        t.push(prev + st.top());
        prev = st.top();
        st.pop();
      }
      t.push(prev);
    }

    stack<int> &st = st1.empty() ? st2 : st1;
    vector<int> ans;
    while (!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }

    return ans;
  }
};
