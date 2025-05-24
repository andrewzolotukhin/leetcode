class Solution {
public:
  vector<int> findWordsContaining(vector<string> &words, char x) {
    vector<int> ans;
    int i = 0;
    for (auto &w : words) {
      if (find(w.begin(), w.end(), x) != w.end()) {
        ans.push_back(i);
      }
      i++;
    }
    return ans;
  }
};
