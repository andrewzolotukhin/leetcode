class Solution {
public:
  vector<string> getLongestSubsequence(vector<string> &words,
                                       vector<int> &groups) {
    vector<string> ans;

    int v = groups[0];
    ans.push_back(words[0]);
    for (int i = 1; i < groups.size(); i++) {
      if (v != groups[i]) {
        v = groups[i];
        ans.push_back(words[i]);
      }
    }
    return ans;
  }
};
