class Solution {
  bool isPalindrome(vector<int> arr) {
    for (int i = 0; i < arr.size() / 2; i++) {
      if (arr[i] != arr[arr.size() - 1 - i])
        return false;
    }
    return true;
  }

public:
  bool isStrictlyPalindromic(int n) {
    for (int i = 2; i <= n - 2; i++) {
      vector<int> d;
      int v = n;
      while (v) {
        d.push_back(v % i);
        v /= i;
      }
      if (!isPalindrome(d))
        return false;
    }

    return true;
  }
};
