class TimeMap {
private:
  map<string, vector<pair<int, string>>> _map;

public:
  TimeMap() { _map = map<string, vector<pair<int, string>>>(); }

  void set(string key, string value, int timestamp) {
    auto &v = _map[key];
    auto it = std::upper_bound(
        v.begin(), v.end(), timestamp,
        [](int t, const pair<int, string> &e) { return t < e.first; });
    v.insert(it, {timestamp, std::move(value)});
  }

  string get(string key, int timestamp) {
    auto itKey = _map.find(key);
    if (itKey == _map.end())
      return "";

    const auto &v = itKey->second;
    auto it = upper_bound(
        v.begin(), v.end(), timestamp,
        [](int t, const pair<int, string> &e) { return t < e.first; });

    if (it == v.begin())
      return "";
    return prev(it)->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
