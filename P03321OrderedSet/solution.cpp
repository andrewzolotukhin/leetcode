class SmartSet {
private:
  unordered_map<int, int> occ;
  set<pair<int, int>> big, small;
  long long ans = 0;
  int n;

public:
  SmartSet(int size) {
    this->n = size;
    this->ans = 0;
  }

  void add(int val) {
    if (occ[val]) {
      _remove({occ[val], val});
    };
    occ[val]++;
    _add({occ[val], val});
  }

  void remove(int val) {
    _remove({occ[val], val});
    occ[val]--;
    if (occ[val]) {
      _add({occ[val], val});
    }
  }

  long long getResult() { return ans; }

private:
  void _add(const pair<int, int> &val) {
    if (big.size() < n || val >= *big.begin()) {
      ans += (long long)val.first * val.second;
      big.insert(val);
      if (big.size() > this->n) {
        ans -= (long long)(big.begin()->first) * (big.begin()->second);
        auto t = *big.begin();
        big.erase(t);
        small.insert(t);
      }
    } else {
      small.insert(val);
    }
  }

  void _remove(const pair<int, int> &val) {
    if (val >= *big.begin()) {
      ans -= (long long)val.first * val.second;
      big.erase(val);
      if (!small.empty()) {
        ans += (long long)(small.rbegin()->first) * (small.rbegin()->second);
        auto t = *small.rbegin();
        small.erase(t);
        big.insert(t);
      }
    } else {
      small.erase(val);
    }
  }
};

class Solution {
public:
  vector<long long> findXSum(vector<int> &nums, int k, int x) {
    SmartSet set(x);

    vector<long long> ans;

    for (int i = 0; i < nums.size(); i++) {
      set.add(nums[i]);
      if (i >= k) {
        set.remove(nums[i - k]);
      }
      if (i >= k - 1) {
        ans.push_back(set.getResult());
      }
    }

    return ans;
  }
};
