class Solution {
public:
  vector<int> addToArrayForm(vector<int> &num, int k) {
    int r = num.size();
    int curr = k;
    vector<int> ans;

    int i = r;
    while (--i >= 0 || curr > 0) {
      if (i >= 0) {
        curr += num[i];
      }
      ans.push_back(curr % 10);
      curr /= 10;
    }
    vector<int> a = vector<int>(ans.rbegin(), ans.rend());

    return a;
  }
};
