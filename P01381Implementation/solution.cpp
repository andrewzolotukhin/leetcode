class CustomStack {
private:
  vector<int> s;
  int size = 0;

public:
  CustomStack(int maxSize) { s = vector<int>(maxSize); }

  void push(int x) {
    if (size == s.size())
      return;
    s[size++] = x;
  }

  int pop() {
    if (size == 0)
      return -1;
    return s[--size];
  }

  void increment(int k, int val) {
    for (int i = 0; i < min(k, (int)s.size()); i++) {
      s[i] += val;
    }
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
