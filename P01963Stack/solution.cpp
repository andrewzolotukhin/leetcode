class Solution {
public:
  int minSwaps(string s) {
    stack<char> st;
    int bal = 0;
    for (char c : s) {
      if (c == '[') {
        st.push(c);
      } else {
        if (!st.empty()) {
          st.pop();
        } else {
          bal++;
        }
      }
    }

    return (bal + 1) / 2;
  }
};
