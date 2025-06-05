class Solution {
private:
  int parent[26];
  int find(int index) {
    if (parent[index] == index)
      return index;
    return parent[index] = find(parent[index]);
  }
  void join(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 == p2)
      return;
    if (p1 > p2) {
      parent[p1] = p2;
    } else {
      parent[p2] = p1;
    }
  }

public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    for (int i = 0; i < 26; i++)
      parent[i] = i;
    for (int i = 0; i < s1.size(); i++) {
      join(s1[i] - 'a', s2[i] - 'a');
    }
    string ans = string(baseStr.size(), 0);
    for (int i = 0; i < baseStr.size(); i++) {
      ans[i] = 'a' + find(baseStr[i] - 'a');
    }
    return ans;
  }
};
