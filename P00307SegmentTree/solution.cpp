class NumArray {
private:
  vector<int> tree;
  int treeSize;

public:
  NumArray(vector<int> &nums) {
    int i = 1;
    while (i < nums.size()) {
      i <<= 1;
    }
    treeSize = i;

    tree = vector<int>(treeSize * 2, 0);

    for (int i = 0; i < nums.size(); i++) {
      tree[treeSize + i] = nums[i];
    }
    for (int i = treeSize - 1; i > 0; i--) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }

  void update(int index, int val) {
    int i = treeSize + index;
    tree[i] = val;
    i /= 2;
    while (i) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
      i /= 2;
    };
  }

  int sumRange(int left, int right) {
    left += treeSize;
    right += treeSize;
    int ans = 0;
    while (left <= right) {
      if (left & 1) {
        ans += tree[left++];
      }
      if (!(right & 1)) {
        ans += tree[right--];
      }
      left /= 2;
      right /= 2;
    }
    return ans;
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
