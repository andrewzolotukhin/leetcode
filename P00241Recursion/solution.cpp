class Solution {
public:
  vector<int> diffWaysToCompute(string expression) {
    vector<int> ans;

    if (expression.size() == 0)
      return ans;

    if (expression.size() == 1) {
      ans.push_back(stoi(expression));
      return ans;
    }

    if (expression.size() == 2 && isdigit(expression[0])) {
      ans.push_back(stoi(expression));
      return ans;
    }

    for (int i = 0; i < expression.size(); i++) {
      auto c = expression[i];

      if (isdigit(c))
        continue;
      vector<int> lr = diffWaysToCompute(expression.substr(0, i));
      vector<int> rr = diffWaysToCompute(expression.substr(i + 1));

      for (int lv : lr) {
        for (int rv : rr) {
          int res = 0;
          switch (c) {
          case '+':
            res = lv + rv;
            break;
          case '-':
            res = lv - rv;
            break;
          case '*':
            res = lv * rv;
            break;
          }

          ans.push_back(res);
        }
      }
    }
    return ans;
  }
};
