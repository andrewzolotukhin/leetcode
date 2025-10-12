class Solution {
public:
  vector<string> stringSequence(string target) {
    string s = "a";
    vector<string> ans;
    if (target == "a")
      return {"a"};

    while (s != target) {
      ans.push_back(s);
      if (s.back() != target[s.size() - 1]) {
        s[s.size() - 1]++;
      } else {
        s += 'a';
      }
    }

    ans.push_back(target);

    return ans;
  }
};
