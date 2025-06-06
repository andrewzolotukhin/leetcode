class Solution {
public:
  string robotWithString(string s) {
    stack<char> ss;
    string ans(s.size(), ' ');
    int index = 0;
    vector<int> freq(26, 0);
    for (int i = s.size() - 1; i >= 0; i--) {
      freq[s[i] - 'a']++;
    }

    auto minKnown = 'a';
    for (char c : s) {
      ss.push(c);
      freq[ss.top() - 'a']--;

      while (minKnown != 'z' && freq[minKnown - 'a'] == 0) {
        minKnown++;
      }

      while (!ss.empty() && ss.top() <= minKnown) {
        ans[index++] = ss.top();
        ss.pop();
      }
    }

    return ans;
  }
};
