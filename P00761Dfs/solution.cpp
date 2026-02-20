class Solution {
public:
  string makeLargestSpecial(string s) {
    int count = 0, c = 0;
    vector<string> ans;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        count++;
      } else {
        count--;
      }

      if (count == 0) {
        ans.push_back('1' + makeLargestSpecial(s.substr(c + 1, i - c - 1)) +
                      '0');
        c = i + 1;
      }
    }

    sort(ans.begin(), ans.end(), greater<string>());

    string r2 = "";
    for (int k = 0; k < ans.size(); k++)
      r2 += ans[k];
    return r2;
  }
};
