class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] == nums[j] && nums[i] == nums[k]) {
                        ans = min(ans, j - i + k - j + k - i);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};