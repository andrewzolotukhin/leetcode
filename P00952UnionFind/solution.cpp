class Solution {
private:
  int find(vector<int> &parents, int i) {
    if (parents[i] <= 0)
      return i;
    return parents[i] = find(parents, parents[i]);
  }
  void join(vector<int> &parents, int i, int j) {
    int p1 = find(parents, i);
    int p2 = find(parents, j);
    if (p1 == p2)
      return;
    parents[p1] += parents[p2];
    parents[p2] = p1;
  }

public:
  int largestComponentSize(vector<int> &nums) {
    vector<int> factors = {
        2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,
        43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101,
        103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
        173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
        241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
    int n = nums.size();
    vector<int> parents(factors.size(), 0);
    unordered_map<int, int> primes;

    /*// slooooow
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
            //if(nums[i] == nums[j]) continue;
            if(__gcd(nums[i], nums[j]) == 1) continue;
            join(parents, i, j);
        }
    }
    */

    for (int i = 0; i < n; i++) {
      auto lf = -1;
      int a = nums[i];
      for (int j = 0; j < factors.size() && factors[j] <= a; j++) {
        if (a % factors[j] == 0) {
          while (a % factors[j] == 0)
            a /= factors[j];
          if (lf >= 0)
            join(parents, j, lf);
          lf = j;
        }
      }

      if (a > 1) {
        auto it = primes.find(a);
        if (it != primes.end()) {
          if (lf != -1 && it->second != -1)
            join(parents, lf, it->second);
          else if (lf != -1 || it->second != -1)
            parents[find(parents, max(lf, it->second))]--;
        }
        if (it == primes.end() || lf >= 0)
          primes[a] = lf;
      }
      if (lf >= 0)
        parents[find(parents, lf)]--;
    }

    return -*min_element(parents.begin(), parents.end());
  }
};
