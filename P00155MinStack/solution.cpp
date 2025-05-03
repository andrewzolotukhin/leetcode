class MinStack {
  int mini = INT_MAX;
  stack<pair<int, int>> st;

public:
  MinStack() { st = stack<pair<int, int>>(); }

  void push(int val) {
    if (val < mini) {
      mini = val;
    }
    st.push({val, mini});
  }

  void pop() {
    if (st.empty()) {
      return;
    }

    st.pop();

    if (st.empty()) {
      mini = INT_MAX;
    } else {
      mini = st.top().second;
    }
  }

  int top() {
    if (st.empty())
      return 0;
    return st.top().first;
  }

  int getMin() { return mini; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
