class Solution {
private:
  int solve(vector<int> &target, int left, int right, int diff) {
    int ans = 0;
    int prev = 0;
    for (auto &x : target) {
      if (prev > x) {
        ans += prev - x;
      }
      prev = x;
    }
    return ans + prev;
    /*
        // slooow
        int start = left, minV = INT_MAX;
        int ans = 0;
        if(left == right) return target[left]-diff;
        if(left >= target.size()) return 0;
        while(start <= right) {
            if(target[start]==diff){
                start++;
                continue;
            }
            int end = start;
            minV = target[start]-diff;
            while(end <= right && target[end] > diff) {
                minV = min(minV, target[end]-diff);
                end++;
            }
            if((end-1 <= right)) {
                ans += minV + solve(target, start, end-1, diff+minV);
            }
            start = end;
        }
        return ans;
*/
  }

public:
  int minNumberOperations(vector<int> &target) {
    int n = target.size();
    return solve(target, 0, n - 1, 0);
  }
};
