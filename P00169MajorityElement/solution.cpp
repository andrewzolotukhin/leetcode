class Solution {
public:
  int majorityElement(vector<int> &nums) {
    // Boyer-Moore Majority algorithm
    int el = INT_MIN, num = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == el) {
        num++;
      } else {
        if (num == 0) {
          el = nums[i];
          num++;
        } else {
          num--;
        }
      }
    }
    return el;
  }
};
