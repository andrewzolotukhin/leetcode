public
class Solution {
public
  int PossibleStringCount(string word) {
    int ans = 1;

    string prefix = string.Empty;
    int n = word.Length;
    for (int i = 0; i < n; i++) {
      int rep = 1;
      while (i + rep < n && word[i + rep] == word[i])
        rep++;
      if (rep > 1) {
        ans += rep - 1;
      }
      i += rep - 1;
    }

    return ans;
  }
}
