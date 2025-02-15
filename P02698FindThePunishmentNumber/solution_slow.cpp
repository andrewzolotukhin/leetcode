#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  void getPossibleSums(vector<int> &d, vector<int> &r) {
    if (d.size() == 1) {
      r.push_back(d[0]);
      return;
    }

    if (d.size() == 2) {
      r.push_back(d[0] + d[1]);
      r.push_back(d[0] * 10 + d[1]);
      return;
    }

    if (d.size() == 3) {
      r.push_back(d[0] + d[1] + d[2]);
      r.push_back(d[0] + d[1] * 10 + d[2]);
      r.push_back(d[0] * 10 + d[1] + d[2]);
      r.push_back(d[0] * 100 + d[1] * 10 + d[2]);

      return;
    }

    for (int i = 0; i < d.size(); i++) {
      if (i == 0) {
        int c = 0;
        for (int j = 0; j < d.size(); j++) {
          c = c * 10 + d[j];
        }
        r.push_back(c);
        continue;
      }

      vector<int> leftArr(d.begin(), d.begin() + i);
      vector<int> rightArr(d.begin() + i, d.end());

      vector<int> lResults, rResults;
      getPossibleSums(leftArr, lResults);
      getPossibleSums(rightArr, rResults);

      for (int i = 0; i < lResults.size(); i++) {
        for (int j = 0; j < rResults.size(); j++) {
          r.push_back(lResults[i] + rResults[j]);
        }
      }
    }

    return;
  }

  bool isMagical(int x, int num) {
    vector<int> digits;
    while (x) {
      digits.push_back(x % 10);
      x /= 10;
    }

    vector<int> rdigits(digits.rbegin(), digits.rend());

    vector<int> possibleSums;
    getPossibleSums(rdigits, possibleSums);

    for (auto possibleSum : possibleSums) {
      if (possibleSum == num) {
        return true;
      }
    }

    return false;
  }

public:
  int punishmentNumber(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
      if (isMagical(i * i, i)) {
        sum += i * i;
      }
    }

    return sum;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  cout << Solution().punishmentNumber(n) << '\n';
}
