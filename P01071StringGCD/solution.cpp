class Solution {
public:
  string elegantSolution(string str1, string str2) {
    return (str1 + str2 == str2 + str1)
               ? str1.substr(0, gcd(size(str1), size(str2)))
               : "";
  }
  string gcdOfStrings(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    int k = gcd(n, m);

    for (int i = k; i >= 1; i--) {
      if (n % i)
        continue;
      if (m % i)
        continue;
      bool match = true;
      for (int j = 0; j < n; j++) {
        if (str1[j] != str1[j % i] || str1[j] != str2[j % i]) {
          match = false;
          break;
        }
      }
      if (!match)
        continue;
      for (int j = 0; j < m; j++) {
        if (str2[j] != str2[j % i] || str2[j] != str1[j % i]) {
          match = false;
          break;
        }
      }
      if (!match)
        continue;
      return str1.substr(0, i);
    }
    return "";
  }
};
