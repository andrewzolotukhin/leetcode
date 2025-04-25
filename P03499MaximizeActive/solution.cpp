class Solution {
public:
  int maxActiveSectionsAfterTrade(string s) {
    // 1110001000001010111
    vector<pair<bool, int>> blocks;
    bool curr = true;
    int currSize = 0, n = s.size();
    int ans = 0, total = 0;
    for (int i = 0; i < n; i++) {
      bool c = s[i] == '1';
      if (c)
        total++;

      if (curr == c) {
        currSize++;
      } else {
        if (currSize > 0) {
          blocks.push_back({curr, currSize});
          // cout << curr << ' ' << currSize << '\n';
        }
        curr = c;
        currSize = 1;
      }
    }
    if (currSize > 0) {
      blocks.push_back({curr, currSize});
      // cout << curr << ' ' << currSize << '\n';
    }

    ans = total;
    for (int i = 0; i < (int)blocks.size() - 2; i++) {
      if (blocks[i].first)
        continue;
      ans = max(ans, total +
                         blocks[i].second
                         //+ blocks[i+1].second
                         + blocks[i + 2].second
                //  - blocks[i+1].second
                //+ (i > 0 ? blocks[i-1].second : 0)
                //+ ((i < blocks.size() - 3)?blocks[i+3].second:0)
      );
    }

    return ans;
  }
};
