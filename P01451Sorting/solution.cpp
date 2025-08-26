class Solution {
public:
  string arrangeWords(string text) {
    text[0] -= 'A';
    text[0] += 'a';

    vector<pair<string, int>> splitted;
    int i = 0;
    istringstream iss(text);
    string w;
    while (iss >> w) {
      splitted.push_back({w, i++});
    }

    sort(splitted.begin(), splitted.end(), [&](auto &a, auto &b) {
      if (a.first.size() == b.first.size()) {
        return a.second < b.second;
      }
      return a.first.size() < b.first.size();
    });

    string ans = "";

    for (auto s : splitted) {
      if (ans.size()) {
        ans += " ";
      }
      ans += s.first;
    }

    ans[0] -= 'a';
    ans[0] += 'A';
    return ans;
  }
};
