class SmallestInfiniteSet {
private:
  int lastUsed;
  priority_queue<int, vector<int>, greater<>> pq;
  unordered_set<int> inSet;

public:
  SmallestInfiniteSet() { lastUsed = 0; }

  int popSmallest() {
    if (pq.empty()) {
      return ++lastUsed;
    }

    if (pq.top() <= lastUsed) {
      int t = pq.top();
      pq.pop();
      inSet.erase(t);
      return t;
    }

    return ++lastUsed;
  }

  void addBack(int num) {
    if (num > lastUsed || inSet.count(num))
      return;
    pq.push(num);
    inSet.insert(num);
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
