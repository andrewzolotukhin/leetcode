/*
 * The optimal solution should leveraage the fact that first or last element of
 * a different color is always should be included, so we can solve it with O(1)
 * space and O(n) time.
 */
class Solution {
public:
  int maxDistance(vector<int> &colors) {
    int n = colors.size();
    vector<int> firstSeen(101, -1), lastSeen(101, -1);
    vector<int> first, last;

    for (int i = 0; i < n; i++) {
      if (firstSeen[colors[i]] == -1) {
        firstSeen[colors[i]] = i;
        first.push_back(i);
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      if (lastSeen[colors[i]] == -1) {
        lastSeen[colors[i]] = i;
        last.push_back(i);
      }
    }

    int ans = 0;

    for (int i = 0; i < first.size(); i++) {
      for (int j = 0; j < last.size(); j++) {
        if (first[i] == last[j] || colors[first[i]] == colors[last[j]])
          continue;

        ans = max(ans, abs(first[i] - last[j]));
      }
    }

    return ans;
  }
};
