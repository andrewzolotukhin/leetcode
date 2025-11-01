class Solution {
public:
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    unordered_map<string, int> m1;
    for (int i = 0; i < list1.size(); i++) {
      m1[list1[i]] = i;
    }
    vector<string> ans;
    int minS = INT_MAX;
    for (int i = 0; i < list2.size(); i++) {
      if (m1.count(list2[i])) {
        int s = i + m1[list2[i]];
        if (s == minS) {
          ans.push_back(list2[i]);
        } else if (s < minS) {
          ans = {list2[i]};
          minS = s;
        }
      }
    }
    return ans;
  }
};
