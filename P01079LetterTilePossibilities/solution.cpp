#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  int countPermutations(vector<int> &freq) {
    int result = 0;
    for (int i = 0; i < 26; i++) {
      if (freq[i] == 0)
        continue;

      freq[i]--;
      result++;
      result += countPermutations(freq);

      freq[i]++;
    }

    return result;
  }

public:
  int numTilePossibilities(string tiles) {
    int n = tiles.size();
    if (n == 1)
      return 1;

    vector<int> freq(26, 0);

    for (int i = 0; i < n; i++) {
      freq[tiles[i] - 'A']++;
    }

    return countPermutations(freq);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  string s;
  cin >> s;

  cout << Solution().numTilePossibilities(s) << '\n';
}
