class FenwickTree {
private:
  vector<int> tree;

public:
  FenwickTree(int size) : tree(size + 1, 0) {}

  void update(int index, int delta) {
    index++;
    while (index < tree.size()) {
      tree[index] += delta;
      index += index & -index;
    }
  }

  int query(int index) {
    index++;
    int res = 0;
    while (index > 0) {
      res += tree[index];
      index -= index & -index;
    }
    return res;
  }
};

class Solution {
public:
  long long goodTriplets(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();

    vector<int> nums2toi(n), rev(n);

    for (int i = 0; i < n; i++)
      nums2toi[nums2[i]] = i;
    for (int i = 0; i < n; i++)
      rev[nums2toi[nums1[i]]] = i;

    long long ans = 0;
    FenwickTree t(n);

    for (int i = 0; i < n; i++) {
      int p = rev[i];
      int l = t.query(p);
      t.update(p, 1);

      int r = n - 1 - p - i + l;
      ans += (long long)l * r;
    }

    return ans;
  }
};
