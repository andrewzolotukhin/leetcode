class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    vector<int> arr;
    int o = 0;
    int ans = 0;
    for (int num : nums) {
      if (num == 0) {
        if (o)
          arr.push_back(o);
        ans = max(ans, o);
        arr.push_back(0);
        o = 0;
      } else {
        o++;
      }
    }
    if (o)
      arr.push_back(o);
    ans = max(ans, o);

    for (int i = 1; i < arr.size() - 1; i++) {
      ans = max(ans, arr[i] + arr[i - 1] + arr[i + 1]);
    }
    return (ans == nums.size() && arr.size() == 1) ? (nums.size() - 1) : ans;
  }
};
