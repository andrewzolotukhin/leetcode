class Solution {
public:
  int numRabbits(vector<int> &answers) {
    int ans = 0;

    vector<int> freq(1001, 0);

    for (auto a : answers) {
      if (a == 0) {
        ans++;
        continue;
      }
      if (freq[a] == 0) {
        ans += a + 1;
      }
      freq[a]++;
      if (freq[a] == a + 1)
        freq[a] = 0;
    }

    return ans;
  }
};
