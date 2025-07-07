class Solution {
public:
  int peakIndexInMountainArray(vector<int> &arr) {
    int n = arr.size(), l = 1, r = n - 2;

    while (l <= r) {
      int mid = (l + r) / 2;

      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        return mid;

      if (arr[mid] < arr[mid + 1]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    assert(false);
  }
};
