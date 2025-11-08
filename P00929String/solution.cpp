class Solution {
public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> eset;

    for (auto &e : emails) {
      string s = "";
      int i = 0;
      bool hasPlus = false;
      while (e[i] != '@') {
        if (!hasPlus) {
          if (e[i] == '+') {
            hasPlus = true;
          } else {
            if (e[i] != '.') {
              s += e[i];
            }
          }
        }
        i++;
      }

      s += '@';
      i++;

      while (i < e.size()) {
        s += e[i++];
      }

      eset.insert(s);
    }
    return eset.size();
  }
};
