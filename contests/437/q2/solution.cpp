#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long maxWeight(vector<int> &pizzas) {
    sort(pizzas.begin(), pizzas.end(), greater<int>());

    long long result = 0;
    int days = pizzas.size() / 4;

    int left = 0;
    int right = pizzas.size() - 1;

    int oddC = (days + 1) / 2;
    int evenC = days / 2;

    for (int day = 0; day < oddC; day++) {
      result += pizzas[left];
      left++;
      right -= 3;
    }

    for (int day = 0; day < evenC; day++) {
      result += pizzas[left + 1];
      left += 2;
      right -= 2;
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n;
  cin >> n;

  vector<int> pizzas(n);

  for (int i = 0; i < n; i++) {
    cin >> pizzas[i];
  }

  cout << Solution().maxWeight(pizzas) << '\n';
}
