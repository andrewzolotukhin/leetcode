class Solution {
public:
  vector<int> colorTheArray(int n, vector<vector<int>> &queries) {
    int currv = 0;
    vector<int> curr(n, 0);
    vector<int> ans;
    for (auto q : queries) {
      int i = q[0];
      int c = q[1];
      int dec = 0;
      if (i > 0 && curr[i] != 0 && curr[i - 1] == curr[i])
        dec--;
      if (i < n - 1 && curr[i] != 0 && curr[i + 1] == curr[i])
        dec--;
      if (i > 0 && curr[i - 1] == c)
        dec++;
      if (i < n - 1 && curr[i + 1] == c)
        dec++;
      currv += dec;
      curr[i] = c;
      ans.push_back(currv);
    }

    return ans;
  }
};
