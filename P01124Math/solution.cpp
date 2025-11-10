class Solution {
public:
  int longestWPI(vector<int> &hours) {
    int ans = 0, score = 0, n = hours.size();
    unordered_map<int, int> seen;

    for (int i = 0; i < n; i++) {
      score += hours[i] > 8 ? 1 : -1;
      if (score > 0) {
        ans = i + 1;
      } else {
        if (seen.find(score) == seen.end()) {
          seen[score] = i;
        }
        if (seen.find(score - 1) != seen.end()) {
          ans = max(ans, i - seen[score - 1]);
        }
      }
    }
    return ans;
  }
};
