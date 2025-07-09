class Solution {
private:
  vector<int> prefix;

public:
  Solution(vector<int> &w) {
    int n = w.size();
    prefix = vector<int>(n, w[0]);
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + w[i];
    }
  }

  int pickIndex() {
    int n = prefix.size();
    int rr = rand() % prefix[n - 1];

    int l = 0, r = n;

    while (l < r) {
      int mid = (r + l) / 2;

      if (prefix[mid] > rr) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
