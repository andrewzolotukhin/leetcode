class Solution {
public:
  int countDays(int days, vector<vector<int>> &meetings) {
    map<int, int> change;
    int prevDay = 0;

    for (int i = 0; i < meetings.size(); i++) {
      change[meetings[i][0]]++;
      change[meetings[i][1] + 1]--;
      prevDay = min(prevDay, meetings[i][0]);
    }

    int ans = prevDay - 1;
    int total = 0;
    int day, c;

    for (auto k : change) {
      day = k.first;
      c = k.second;
      if (total == 0) {
        ans += day - prevDay;
      }
      total += c;
      prevDay = day;
    }

    ans += days - prevDay + 1;

    return ans;

    // 1 2  3 4 5 6  7 8 9 10
    // 1 0 -1 0 1 0 -1 0 1 -1
    // 1 1  0 0 1 1  0 0 1  0
  }
};
