class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    vector<int> vtoi(1002, -1);
    for (int i = 0; i < arr2.size(); i++) {
      vtoi[arr2[i]] = i;
    }

    auto comp = [&](int a, int b) {
      if (vtoi[a] != -1 && vtoi[b] != -1) {
        return vtoi[a] < vtoi[b];
      }

      if (vtoi[a] == -1 && vtoi[b] == -1) {
        return a < b;
      }

      return vtoi[a] != -1;
    };

    sort(arr1.begin(), arr1.end(), comp);
    return arr1;
  }
};
