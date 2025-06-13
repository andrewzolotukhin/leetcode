class Solution {
public:
  bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size())
      return false;
    int n = word1.size();
    unordered_map<char, int> m1, m2;
    for (char c : word1)
      m1[c]++;
    for (char c : word2)
      m2[c]++;

    for (auto [k, v] : m1) {
      if (m2.count(k) == 0)
        return false;
    }
    for (auto [k, v] : m2) {
      if (m1.count(k) == 0)
        return false;
    }

    vector<int> f1, f2;
    for (auto [k, v] : m1)
      f1.push_back(v);
    for (auto [k, v] : m2)
      f2.push_back(v);

    if (f1.size() != f2.size())
      return false;

    sort(f1.begin(), f1.end());
    sort(f2.begin(), f2.end());

    for (int i = 0; i < f1.size(); i++) {
      if (f1[i] != f2[i])
        return false;
    }

    return true;
  }
};
