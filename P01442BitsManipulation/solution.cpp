// The correct solution is O(n^2)
// this one is O(n^3)
class Solution {
public:
  int countTriplets(vector<int> &arr) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] ^ arr[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j; k < n; k++) {
          int left = prefix[i];
          int right = prefix[j] ^ left;
          int middle = prefix[k + 1] ^ prefix[j];
          if (middle == right)
            ans++;
        }
      }
    }

    return ans;
  }
};
