class Solution {
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int n = arr.size();
    int s = 0;
    int ans = 0;
    for (int i = 0; i < k; i++)
      s += arr[i];
    if (s >= threshold * k)
      ans++;
    for (int l = k; l < n; l++) {
      s += arr[l];
      s -= arr[l - k];
      if (s >= threshold * k)
        ans++;
    }

    return ans;
  }
};
