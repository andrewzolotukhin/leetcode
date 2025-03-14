#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool canDistribute(vector<int> &candies, long long k, int size) {

    for (auto c : candies) {
      k -= (c / size);
      if (k <= 0)
        return true;
    }

    return false;
  }

public:
  int maximumCandies(vector<int> &candies, long long k) {
    int maxPossible = 0;

    for (auto c : candies) {
      maxPossible = max(maxPossible, c);
    }

    int n = candies.size();
    int left = 0;
    int right = maxPossible;
    int answer = 0;

    while (left < right) {
      int middle = (right + left + 1) / 2;

      if (canDistribute(candies, k, middle)) {
        answer = max(answer, middle);
        left = middle;
      } else {
        right = middle - 1;
      }
    }
    return answer;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  long long k;
  cin >> n >> k;

  vector<int> candies(n);

  for (auto &c : candies)
    cin >> c;

  cout << Solution().maximumCandies(candies, k) << '\n';
}
