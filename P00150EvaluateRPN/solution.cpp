class Solution {
private:
  int evaluate(stack<string> &st) {
    if (st.empty())
      return 0;

    auto op = st.top();
    st.pop();

    if (op.size() == 1 && (!(op[0] >= '0' && op[0] <= '9'))) {
      switch (op[0]) {
      case '+':
        return evaluate(st) + evaluate(st);
      case '-':
        return -(evaluate(st) - evaluate(st));
      case '*':
        return evaluate(st) * evaluate(st);
      case '/':
        int p1 = evaluate(st);
        int p2 = evaluate(st);
        return p2 / p1;
      }
    }

    return stoi(op);
  }

public:
  int evalRPN(vector<string> &tokens) {
    stack<string> st;
    for (auto t : tokens)
      st.push(t);

    return evaluate(st);
  }
};
