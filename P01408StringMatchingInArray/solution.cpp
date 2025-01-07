#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<string> stringMatching(vector<string> &words) {
    vector<string> result;

    unordered_set<string> resultSet;

    for (int i = 0; i < words.size() - 1; i++) {
      for (int j = i + 1; j < words.size(); j++) {
        string a = words[i], b = words[j];
        if (a.size() > b.size()) {
          string t = a;
          a = b;
          b = t;
        }
        if (b.find(a.c_str()) != -1) {
          resultSet.insert(a);
        }
      }
    }

    for (auto s : resultSet) {
      result.push_back(s);
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  vector<string> words;

  while (n--) {
    string s;
    cin >> s;
    words.push_back(s);
  }

  Solution s;

  auto result = s.stringMatching(words);

  for (auto s : result) {
    cout << s << '\n';
  }
}
