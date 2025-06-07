class Solution {
public:
  string clearStars(string s) {

    vector<stack<int>> stacks(26);
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '*') {
        for (int k = 0; k < 26; k++) {
          if (!stacks[k].empty()) {
            s[stacks[k].top()] = '*';
            stacks[k].pop();
            break;
          }
        }
      } else {
        stacks[s[i] - 'a'].push(i);
      }
    }

    string ans = "";
    for (auto c : s) {
      if (c != '*')
        ans += c;
    }
    return ans;
  }
};
