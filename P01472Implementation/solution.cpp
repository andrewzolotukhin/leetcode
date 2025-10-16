class BrowserHistory {
private:
  vector<string> history;
  int curr, last;

public:
  BrowserHistory(string homepage) {
    history.push_back(homepage);
    curr = 0;
    last = 0;
  }

  void visit(string url) {
    if (curr + 1 < history.size()) {
      history[curr + 1] = url;
      history.resize(curr + 2);
    } else {
      history.push_back(url);
    }
    curr++;
    last = curr;
  }

  string back(int steps) {
    curr = max(0, curr - steps);
    return history[curr];
  }

  string forward(int steps) {
    curr = min(last, curr + steps);
    return history[curr];
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
