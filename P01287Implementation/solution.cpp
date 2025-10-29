class Solution {
public:
  int findSpecialInteger(vector<int> &arr) {
    unordered_map<int, int> freq;
    for (auto &v : arr)
      freq[v]++;
    int n = arr.size();
    for (auto &[k, v] : freq) {
      if (v > n / 4)
        return k;
    }
    assert(false);
  }
};
