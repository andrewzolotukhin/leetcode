class MedianFinder {
  priority_queue<int> maxPq;
  priority_queue<int, vector<int>, greater<int>> minPq;
  int total;

public:
  MedianFinder() {
    maxPq = priority_queue<int>();
    minPq = priority_queue<int, vector<int>, greater<int>>();
    total = 0;
  }

  void addNum(int num) {
    if (minPq.empty() || num >= minPq.top()) {
      minPq.push(num);
      if (minPq.size() > maxPq.size() + 1) {
        maxPq.push(minPq.top());
        minPq.pop();
      }
    } else {
      maxPq.push(num);
      if (maxPq.size() > minPq.size()) {
        minPq.push(maxPq.top());
        maxPq.pop();
      }
    }
  }

  double findMedian() {
    if ((maxPq.size() + minPq.size()) % 2 == 0) {
      return (double)(minPq.top() + maxPq.top()) / 2;
    } else {
      return minPq.top();
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
