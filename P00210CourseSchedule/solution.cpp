class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> inorder(numCourses, 0);
    vector<vector<int>> adj(numCourses, vector<int>());

    for (auto pr : prerequisites) {
      adj[pr[1]].push_back(pr[0]);
      inorder[pr[0]]++;
    }

    vector<int> q;

    for (int i = 0; i < numCourses; i++) {
      if (inorder[i] == 0)
        q.push_back(i);
    }

    vector<int> ans;
    while (q.size()) {
      auto curr = q[q.size() - 1];
      q.pop_back();
      ans.push_back(curr);

      for (auto n : adj[curr]) {
        if (--inorder[n] == 0) {
          q.push_back(n);
        }
      }
    }

    if (ans.size() != numCourses) {
      return vector<int>();
    }

    return ans;
  }
};
