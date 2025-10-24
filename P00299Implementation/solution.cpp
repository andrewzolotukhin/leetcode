class Solution {
public:
  string getHint(string secret, string guess) {
    unordered_map<char, int> pos;
    int bulls = 0;
    unordered_map<char, int> freq;
    int n = secret.size();
    int cows = 0;
    for (int i = 0; i < n; i++) {
      if (secret[i] == guess[i]) {
        bulls++;
      } else {
        freq[secret[i]]++;
        pos[guess[i]]++;
      }
    }

    unordered_map<char, int> seen;
    for (auto [c, v] : pos) {
      cows += min(freq[c], v);
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
  }
};
