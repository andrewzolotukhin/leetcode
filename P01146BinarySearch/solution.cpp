class SnapshotArray {
private:
  vector<vector<pair<int, int>>> _vals;
  int _snapId;

public:
  SnapshotArray(int length) {
    _vals = vector<vector<pair<int, int>>>(length, vector<pair<int, int>>());
    _snapId = 0;
  }

  void set(int index, int val) {
    auto &a = _vals[index];
    if (a.empty() || a.back().first != _snapId)
      a.push_back({_snapId, val});
    else
      a.back().second = val;
  }

  int snap() { return _snapId++; }

  int get(int index, int snap_id) {
    auto &vals = _vals[index];
    int l = 0, r = vals.size() - 1;
    if (vals.empty())
      return 0;

    auto it =
        upper_bound(vals.begin(), vals.end(), pair<int, int>{snap_id, INT_MAX},
                    [](auto const &key, auto const &elem) {
                      return key.first < elem.first;
                    });

    if (it == vals.begin())
      return 0;
    --it;
    return it->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
