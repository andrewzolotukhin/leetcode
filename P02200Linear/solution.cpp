class Solution {
public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    vector<int> keyPos;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] == key) {
        keyPos.push_back(i);
      }
    }

    if (keyPos.size() == 0)
      return {};

    vector<int> ans;
    int cp = keyPos[0];
    int p = 0;
    for (int i = 0; i < n; i++) {
      if (p < keyPos.size() - 1 && abs(i - cp) >= abs(i - keyPos[p + 1])) {
        p++;
        cp = keyPos[p];
      }
      if (abs(i - cp) > k && p == keyPos.size())
        break;
      if (abs(i - cp) > k)
        continue;
      ans.push_back(i);
    }
    return ans;
  }
};
