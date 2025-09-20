#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

class Router {
private:
  struct Packet {
    int src, dest, ts, id;
  };

  deque<Packet> deq;                       // FIFO packets
  unordered_set<string> used;              // uniqueness check
  unordered_map<int, ordered_set> packets; // dest -> timestamps

  int dummyValue = 0; // ensures uniqueness of (ts, id)
  int memoryLimit;

  string makeKey(int src, int dest, int ts) {
    return to_string(src) + "!" + to_string(dest) + "!" + to_string(ts);
  }

public:
  Router(int memoryLimit) : memoryLimit(memoryLimit) {}

  bool addPacket(int src, int dest, int ts) {
    string key = makeKey(src, dest, ts);
    if (used.count(key))
      return false;

    // Evict oldest if at limit
    if ((int)deq.size() == memoryLimit) {
      auto old = deq.front();
      deq.pop_front();
      used.erase(makeKey(old.src, old.dest, old.ts));
      packets[old.dest].erase({old.ts, old.id});
    }

    // Insert new packet
    deq.push_back({src, dest, ts, dummyValue});
    used.insert(key);
    packets[dest].insert({ts, dummyValue++});
    return true;
  }

  vector<int> forwardPacket() {
    if (deq.empty())
      return {};
    auto p = deq.front();
    deq.pop_front();
    used.erase(makeKey(p.src, p.dest, p.ts));
    packets[p.dest].erase({p.ts, p.id});
    return {p.src, p.dest, p.ts};
  }

  int getCount(int dest, int startTime, int endTime) {
    auto &os = packets[dest];
    return os.order_of_key({endTime + 1, 0}) - os.order_of_key({startTime, 0});
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
