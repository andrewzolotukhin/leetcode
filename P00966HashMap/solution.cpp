class Solution {
private:
  inline bool isVovel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }

public:
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    unordered_set<string> init;
    unordered_map<string, string> cap, vow;

    for (auto w : wordlist) {
      init.insert(w);

      string lower = w;
      for (char &c : lower) {
        c = tolower(c);
      }

      if (cap.count(lower) == 0)
        cap[lower] = w;

      string dw = "";
      for (char c : w) {
        c = tolower(c);
        if (!isVovel(c)) {
          dw += c;
        } else {
          dw += '#';
        }
      }

      if (vow.count(dw) == 0) {
        vow[dw] = w;
      }
    }

    vector<string> ans;

    for (auto q : queries) {
      string r;
      if (init.count(q)) {
        r = q;
      } else {
        string lc = q;
        for (char &c : lc) {
          c = tolower(c);
        }

        if (cap.count(lc)) {
          r = cap[lc];
        } else {
          string dw = "";
          for (char c : lc) {
            c = tolower(c);
            if (!isVovel(c)) {
              dw += c;
            } else {
              dw += '#';
            }
          }
          if (vow.count(dw)) {
            r = vow[dw];
          } else {
            r = "";
          }
        }
      }
      ans.push_back(r);
    }

    return ans;
  }
};
