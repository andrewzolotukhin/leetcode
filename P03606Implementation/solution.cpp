class Solution {
private:
  bool hasOnlyValidChars(string &code) {
    if (code.size() == 0)
      return false;
    for (auto c : code) {
      if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9') || c == '_'))
        return false;
    }
    return true;
  }

public:
  vector<string> validateCoupons(vector<string> &code,
                                 vector<string> &businessLine,
                                 vector<bool> &isActive) {
    vector<pair<string, string>> cand;

    for (int i = 0; i < code.size(); i++) {
      if (!isActive[i])
        continue;
      if (!(businessLine[i] == "electronics" || businessLine[i] == "grocery" ||
            businessLine[i] == "pharmacy" || businessLine[i] == "restaurant")) {
        continue;
      }

      if (!hasOnlyValidChars(code[i]))
        continue;
      cand.push_back({code[i], businessLine[i]});
    }

    sort(cand.begin(), cand.end(),
         [&](pair<string, string> &a, pair<string, string> &b) {
           if (a.second == b.second) {
             return a.first < b.first;
           }
           return a.second < b.second;
         });

    vector<string> ans;
    for (auto c : cand) {
      ans.push_back(c.first);
    }
    return ans;
  }
};
