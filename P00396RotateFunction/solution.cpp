class Solution {
public:
  int maxRotateFunction(vector<int> &nums) {
    // F(0) = a1*0 + a2*1 + a3*2 + a4*3 + a5*4
    // F(1) = a1*1 + a2*2 + a3*3 + a4*4 + a5*0
    // F(1) - F(0) = a1*(1-0) + a2*(2-1) + a3*(3-2) + a4*(4-3) + a5*(0-4)
    // = sum - 4*a5
    // F(2) = a1*2 + a2*3 + a3*4 + a4*0 + a5*1
    // F(2)-F(1) = a1 + a2 + a3 - 4*a4 + a5

    long long sum = 0;
    long long f = 0;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      f += i * nums[i];
    }
    long long ans = f;

    for (int l = n - 1; l >= 1; l--) {
      f += sum - n * nums[l];
      if (f > ans)
        ans = f;
    }

    return (int)ans;
  }
};
