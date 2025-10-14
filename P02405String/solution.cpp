class Solution {
public:
  int partitionString(string s) {
    int ans = 1;
    string temp = "";

    for (char c : s) {
      if (temp.find(c) != temp.npos) {
        ans++;
        temp = "";
      }
      temp.push_back(c);
    }
    return ans;
  }
};
