class Solution {
public:
  long long putMarbles(vector<int> &weights, int k) {
    if (k == weights.size())
      return 0LL;

    vector<int> parts(weights.size() - 1);

    for (int i = 1; i < weights.size(); i++) {
      parts[i - 1] = weights[i] + weights[i - 1];
    }

    sort(parts.begin(), parts.end());

    long long b = 0, s = 0;

    for (int i = 0; i < k - 1; i++) {
      s += parts[i];
      b += parts[parts.size() - 1 - i];
    }

    return b - s;
  }
};
