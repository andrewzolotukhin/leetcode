class Solution {
public:
  int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration,
                         vector<int> &waterStartTime,
                         vector<int> &waterDuration) {
    vector<int> first, second;
    int n = landStartTime.size(), m = waterStartTime.size();
    for (int i = 0; i < n; i++) {
      first.push_back(landStartTime[i] + landDuration[i]);
    }
    for (int i = 0; i < m; i++) {
      second.push_back(waterStartTime[i] + waterDuration[i]);
    }

    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    int ans = INT_MAX;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        // if(waterStartTime[i] < first[j] && waterStartTime[i] +
        // waterDuration[i] < first[j]) continue;
        ans = min(ans, max(first[j], waterStartTime[i]) + waterDuration[i]);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // if(landStartTime[i] < second[j] && landStartTime[i] + landDuration[i]
        // < second[j]) continue;
        ans = min(ans, max(second[j], landStartTime[i]) + landDuration[i]);
      }
    }
    // 9, 14, 209, 175, 158, 162, 91
    return ans;
  }
};
