class Solution {
public:
  int minimumDeletions(string word, int k) {
    vector<int> f(26, 0);
    for (auto c : word)
      f[c - 'a']++;

    vector<int> nz;
    for (int v : f)
      if (v)
        nz.push_back(v);

    sort(nz.begin(), nz.end());

    int ans = word.size();

    for (int i = 0; i < nz.size(); i++) {
      int c = 0;
      for (int j = 0; j < nz.size(); j++) {
        if (i == j)
          continue;
        if (nz[i] > nz[j]) {
          c += nz[j];
        } else if (nz[j] > nz[i] + k) {
          c += nz[j] - nz[i] - k;
        }
      }
      ans = min(ans, c);
    }
    return ans;
  }
};
