class Solution {
public:
  int wateringPlants(vector<int> &plants, int capacity) {
    int ans = 0;
    int c = capacity;
    int pos = 0;
    while (pos < plants.size()) {
      if (c < plants[pos]) {
        ans += 2 * pos;
        c = capacity - plants[pos];
      } else {
        c -= plants[pos];
      }
      pos++;
      ans++;
    }

    return ans;
  }
};
