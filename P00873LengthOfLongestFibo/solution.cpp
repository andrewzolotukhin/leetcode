class Solution {
public:
  int lenLongestFibSubseq(vector<int> &arr) {
    int i, j, n = arr.size();

    map<int, int> indexes;
    vector<int> sums;

    for (i = 0; i < n; i++) {
      indexes[arr[i]] = i;
    }

    int result = 0;

    for (i = 0; i < n - 1; i++) {
      for (j = i + 1; j < n; j++) {
        int current = 0;

        int cx = arr[i], cy = arr[j];

        while (indexes.count(cx + cy)) {
          int nextIndex = cx + cy;
          if (current == 0) {
            current = 3;
          } else {
            current++;
          }
          cx = cy;
          cy = arr[indexes[nextIndex]];
        }

        result = max(result, current);
      }
    }

    return result;
  }
};
