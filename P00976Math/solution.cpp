class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    int ans = 0;
    sort(nums.rbegin(), nums.rend());

    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        for (int k = j + 1; k < nums.size(); k++) {
          int a = nums[i], b = nums[j], c = nums[k];
          if (b + c <= a)
            break;
          return a + b + c;
        }
      }
    }

    return ans;
  }
};
