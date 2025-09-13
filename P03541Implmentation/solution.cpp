class Solution {
private:
  inline bool isVovel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

public:
  int maxFreqSum(string s) {
    vector<int> freq(26);

    for (auto c : s) {
      freq[c - 'a']++;
    }

    int a1 = 0, a2 = 0;

    for (char i = 'a'; i <= 'z'; i++) {
      if (isVovel(i)) {
        a1 = max(a1, freq[i - 'a']);
      } else {
        a2 = max(a2, freq[i - 'a']);
      }
    }

    return a1 + a2;
  }
};
