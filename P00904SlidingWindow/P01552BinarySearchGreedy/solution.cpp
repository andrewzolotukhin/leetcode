class Solution {
private:
  bool canPlace(vector<int> &position, int gap, int m) {
    int prev = 0;
    m--;
    for (int i = 1; i < position.size(); i++) {
      if (m == 0)
        break;
      if (position[i] - position[prev] >= gap) {
        prev = i;
        m--;
      }
    }
    // cout << (m==0) << '\n';
    return (m == 0);
  }

public:
  int maxDistance(vector<int> &position, int m) {
    sort(position.begin(), position.end());
    int l = 1, r = position.back() - position[0];

    int ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      // cout << mid << ' ';
      if (canPlace(position, mid, m)) {
        ans = max(ans, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }
};
