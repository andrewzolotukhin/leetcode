class Solution {
public:
  vector<int> findEvenNumbers(vector<int> &digits) {
    int freq[11];
    memset(&freq, 0, sizeof(freq));

    for (auto d : digits)
      freq[d]++;

    vector<int> ans;

    for (int i = 100; i < 1000; i++) {
      if (i & 1)
        continue;
      bool good = true;
      int t = i;
      vector<int> f2(10, 0);
      for (int j = 0; j < 3; j++) {
        int d = t % 10;
        f2[d]++;
        if (f2[d] > freq[d]) {
          good = false;
          break;
        }
        t /= 10;
      }
      if (good)
        ans.push_back(i);
    }
    return ans;
  }
};
