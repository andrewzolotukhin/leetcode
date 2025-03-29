#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  long long pwr(long long x, long long n, long long mod) {
    if (n == 0)
      return 1;
    if (x == 1)
      return 1;
    if (n < 0)
      return 0LL;

    long long ans = 1;

    while (n > 0) {
      if (n & 1) {
        ans = (ans * x) % mod;
      }

      x = (x * x) % mod;
      n /= 2;
    }

    return ans;
  }
  int getRanks(int x, vector<int> &primes) {
    int result = 0;

    for (auto prime : primes) {
      if (prime * prime > x)
        break;
      if (x % prime != 0)
        continue;

      result++;
      while (x % prime == 0) {
        x /= prime;
      }
    }

    if (x > 1)
      result++;

    return result;
  }

public:
  int maximumScore(vector<int> &nums, int k) {
    int mod = 1e9 + 7;
    int primeLimit = 100000;
    vector<int> isPrime(primeLimit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= primeLimit; i++) {
      if (!isPrime[i])
        continue;
      for (int j = i * i; j < primeLimit + 1; j += i) {
        isPrime[j] = false;
      }
    }

    vector<int> primes;
    for (int i = 2; i <= primeLimit; i++) {
      if (isPrime[i]) {
        primes.push_back(i);
      }
    }

    map<int, int> ranks;

    for (auto num : nums) {
      if (ranks.count(num))
        continue;
      ranks[num] = getRanks(num, primes);
    }

    vector<int> ra(nums.size());
    for (int i = 0; i < ra.size(); i++) {
      ra[i] = ranks[nums[i]];
    }
    vector<int> left(nums.size(), -1);
    vector<int> right(nums.size(), nums.size());

    stack<int> st;

    for (int i = 0; i < ra.size(); i++) {
      while (!st.empty() && ra[st.top()] < ra[i]) {
        int topIndex = st.top();
        st.pop();

        right[topIndex] = i;
      }

      if (!st.empty())
        left[i] = st.top();

      st.push(i);
    }

    vector<long long> subarrays(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      subarrays[i] = (long long)(right[i] - i) * (i - left[i]);
    }

    vector<pair<int, int>> numsWithIndex(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      numsWithIndex[i] = {nums[i], i};
    }

    sort(numsWithIndex.begin(), numsWithIndex.end(), greater<>());

    long long ans = 1;
    int idx = 0;

    while (k > 0) {
      int item = numsWithIndex[idx].first;
      int j = numsWithIndex[idx].second;
      idx++;

      long long ops = min((long long)k, subarrays[j]);

      ans = (ans * pwr(item, ops, mod)) % mod;

      k -= ops;
    }

    return ans;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, k;
  cin >> n >> k;

  vector<int> nums(n);
  for (auto &num : nums)
    cin >> num;

  cout << Solution().maximumScore(nums, k) << '\n';
}
