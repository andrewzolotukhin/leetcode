class Solution {
public:
  int minSteps(string s, string t) {
    unordered_map<char, int> fs, ft;
    for (auto c : s)
      fs[c]++;
    for (auto c : t)
      ft[c]++;

    int ans = 0;
    for (char i = 'a'; i <= 'z'; i++) {
      if (fs[i] || ft[i]) {
        ans += abs(fs[i] - ft[i]);
      }
    }

    return ans / 2;
  }
};
