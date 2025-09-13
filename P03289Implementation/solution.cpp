class Solution {
public:
  vector<int> getSneakyNumbers(vector<int> &nums) {
    map<int, int> freq;

    vector<int> ans;
    for (auto n : nums)
      if (++freq[n] == 2)
        ans.push_back(n);
    return ans;
  }
};
