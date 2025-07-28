class Solution {
private:
  bool isBalanced(int n) {
    vector<int> c(10, 0);
    do {
      c[n % 10]++;
      n /= 10;
    } while (n);
    for (int i = 0; i < 10; i++) {
      if (c[i] == 0)
        continue;
      if (c[i] != i)
        return false;
    }
    return true;
  }

public:
  int nextBeautifulNumber(int n) {
    int t = n + 1;
    while (!isBalanced(t))
      t++;
    return t;
  }
};
