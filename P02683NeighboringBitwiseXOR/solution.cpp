#include <bits/stdc++.h>
#include <bitset>
using namespace std;

class Solution {
  bool iterate(bool first, vector<int> &derived) {
    bitset<100005> *originalRef = new std::bitset<100005>();

    auto original = *originalRef;

    original[0] = first;

    for (int i = 1; i < derived.size(); i++) {
      original[i] = original[i - 1] ^ (derived[i - 1] == 1);
    }

    // cout << f << " " << l << " " << original << '\n';
    if ((original[0] ^ original[derived.size() - 1]) ==
        (derived[derived.size() - 1] == 1)) {
      delete originalRef;
      return true;
    }

    delete originalRef;
    return false;
  }

public:
  bool doesValidArrayExist(vector<int> &derived) {
    if (derived.size() == 1) {
      return derived[0] != 1;
    }

    if (iterate(true, derived)) {
      return true;
    }

    return iterate(false, derived);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  vector<int> d;

  cin >> n;

  while (n--) {
    int x;
    cin >> x;
    d.push_back(x);
  }

  Solution s;
  cout << (s.doesValidArrayExist(d) ? "YES" : "NO") << '\n';
}
