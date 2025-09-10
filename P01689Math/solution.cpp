class Solution {
public:
  int minPartitions(string n) {
    char ans = '0';
    for (auto c : n) {
      if (c > ans)
        ans = c;
    }

    return ans - '0';
  }
};
