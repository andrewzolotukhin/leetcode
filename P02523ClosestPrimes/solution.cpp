class Solution {
public:
  vector<int> closestPrimes(int left, int right) {

    vector<bool> isPrime(right + 1, true);
    isPrime[1] = false;

    for (long long i = 2; i <= right; i++) {
      if (!isPrime[i])
        continue;
      for (long long j = i * i; j <= right; j += i) {
        isPrime[j] = false;
      }
    }

    int prevPrime = -1;
    int minDiff = INT_MAX;
    vector<int> result = {-1, -1};

    for (int i = right; i >= left; i--) {
      if (isPrime[i]) {
        if (prevPrime == -1) {
          prevPrime = i;
          continue;
        }

        if (prevPrime - i <= minDiff) {
          result = {i, prevPrime};
          minDiff = prevPrime - i;
        }
        prevPrime = i;
      }
    }

    return result;
  }
};
