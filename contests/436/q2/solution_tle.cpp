#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  map<int, set<int>> divisorsCache;
  set<int> allDivisors;
  set<int> getDivisors(int n) {
    if (divisorsCache.count(n)) {
      return divisorsCache[n];
    }
    set<int> divisors;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divisors.insert(i);
        allDivisors.insert(i);
        if (i * i != n) {
          divisors.insert(n / i);
          allDivisors.insert(n / i);
        }
      }
    }
    divisors.insert(n);
    allDivisors.insert(n);
    divisorsCache[n] = divisors;
    return divisors;
  }

public:
  vector<int> assignElements(vector<int> &groups, vector<int> &elements) {
    int n = groups.size();
    int m = elements.size();

    vector<int> result(n, -1);
    unordered_map<int, int> groupToElement;

    for (int i = 0; i < n; i++) {
      getDivisors(groups[i]);
    }

    vector<pair<int, int>> validElements;
    set<int> addedElements;

    for (int i = 0; i < m; i++) {
      if (!addedElements.count(elements[i]) && allDivisors.count(elements[i])) {
        validElements.push_back({elements[i], i});
        addedElements.insert(elements[i]);
      }
    }

    int k = validElements.size();

    for (int i = 0; i < n; i++) {
      if (groupToElement.count(groups[i])) {
        result[i] = groupToElement[groups[i]];
        continue;
      }
      // auto divisors = getDivisors(groups[i]);
      for (int j = 0; j < k; j++) {
        if (validElements[j].first > groups[i])
          continue;
        if (validElements[j].first == 1 ||
            groups[i] % validElements[j].first == 0) {
          result[i] = validElements[j].second;
          groupToElement[groups[i]] = validElements[j].second;
          break;
        }
      }
    }

    return result;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;
  vector<int> groups(n), elements(m);
  for (int i = 0; i < n; i++) {
    cin >> groups[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> elements[i];
  }

  auto result = Solution().assignElements(groups, elements);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << '\n';
  }
}
