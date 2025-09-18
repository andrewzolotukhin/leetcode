
auto comp = [](array<int, 4> &a, array<int, 4> &b) {
  // priority
  if (a[1] == b[1]) {
    // taskId
    return a[2] < b[2];
  }
  return a[1] < b[1];
};

class TaskManager {
private:
  priority_queue<array<int, 4>, vector<array<int, 4>>, decltype(comp)> pq;
  unordered_map<int, int> versions;
  unordered_map<int, int> users;
  unordered_map<int, bool> removed;

public:
  TaskManager(vector<vector<int>> &tasks) {
    pq = priority_queue<array<int, 4>, vector<array<int, 4>>, decltype(comp)>(
        comp);

    for (auto t : tasks) {
      array<int, 4> v = {versions[t[1]]++, t[2], t[1], t[0]};
      users[t[1]] = t[0];
      pq.push(v);
    }
  }

  void add(int userId, int taskId, int priority) {
    array<int, 4> v = {versions[taskId]++, priority, taskId, userId};
    users[taskId] = userId;
    removed[taskId] = false;
    pq.push(v);
  }

  void edit(int taskId, int newPriority) {
    array<int, 4> v = {versions[taskId]++, newPriority, taskId, users[taskId]};
    pq.push(v);
  }

  void rmv(int taskId) { removed[taskId] = true; }

  int execTop() {
    while (!pq.empty() &&
           (removed[pq.top()[2]] || versions[pq.top()[2]] - 1 != pq.top()[0]))
      pq.pop();
    if (pq.empty())
      return -1;

    auto top = pq.top();
    pq.pop();

    return top[3];
  }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
