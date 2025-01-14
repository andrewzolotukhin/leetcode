#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    long long r = 0, a = 0, b = 0;

    vector<int> res;

    for (int i = 0; i < A.size(); i++) {
      a |= (1LL << (A[i] - 1));
      b |= (1LL << (B[i] - 1));
      r = a & b;
      res.push_back(__builtin_popcountll(r));
    }

    return res;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<int> a, b;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }

  Solution s;

  auto res = s.findThePrefixCommonArray(a, b);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
}
