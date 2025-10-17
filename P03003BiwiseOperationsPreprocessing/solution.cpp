class Solution {
public:
  int maxPartitionsAfterOperations(string s, int k) {
    int n = s.size();
    vector<vector<int>> left(n, vector<int>(3)), right(n, vector<int>(3));

    int num = 0, mask = 0, count = 0;
    for (int i = 0; i < n - 1; i++) {
      int b = 1 << (s[i] - 'a');
      if (!(mask & b)) {
        count++;
        if (count <= k) {
          mask |= b;
        } else {
          num++;
          mask = b;
          count = 1;
        }
      }

      left[i + 1][0] = num;
      left[i + 1][1] = mask;
      left[i + 1][2] = count;
    }

    num = 0, mask = 0, count = 0;

    for (int i = n - 1; i > 0; i--) {
      int b = (1 << (s[i] - 'a'));

      if (!(mask & b)) {
        count++;
        if (count <= k) {
          mask |= b;
        } else {
          num++;
          mask = b;
          count = 1;
        }
      }
      right[i - 1][0] = num;
      right[i - 1][1] = mask;
      right[i - 1][2] = count;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
      int segment = left[i][0] + right[i][0] + 2;
      int totalMask = left[i][1] | right[i][1];
      int totalCount = 0;
      while (totalMask) {
        totalMask = totalMask & (totalMask - 1);
        totalCount++;
      }
      if (left[i][2] == k && right[i][2] == k && totalCount < 26) {
        segment++;
      } else if (min(totalCount + 1, 26) <= k) {
        segment--;
      }
      ans = max(ans, segment);
    }

    return ans;
  }
};
