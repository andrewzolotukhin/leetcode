class Solution {
public:
  int minOperations(vector<int> &nums) {
    unordered_set<int> seen;
    stack<int> stack;
    int ans = 0;

    for (int &curr : nums) {
      if (curr == 0) {
        seen.clear();
        continue;
      }
      while (!stack.empty() && stack.top() > curr) {
        seen.erase(stack.top());
        stack.pop();
      }

      if (!seen.count(curr)) {
        ans++;
        seen.insert(curr);
      }
      stack.push(curr);
    }
    return ans;
  }
};
