#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  long long countAtLeast(string word, int k) {
    unordered_map<char, int> vowels;

    int consonants = 0, n = word.size();
    int l = 0, r = 0;
    long long result = 0;

    while (r < n) {
      if (isVowel(word[r])) {
        vowels[word[r]]++;
      } else {
        consonants++;
      }

      while (vowels.size() == 5 && consonants >= k) {
        result += n - r;
        if (isVowel(word[l])) {
          vowels[word[l]]--;
          if (vowels[word[l]] == 0) {
            vowels.erase(word[l]);
          }
        } else {
          consonants--;
        }
        l++;
      }
      r++;
    }

    return result;
  }

public:
  long long countOfSubstrings(string word, int k) {
    return countAtLeast(word, k) - countAtLeast(word, k + 1);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int k;
  string word;
  cin >> k >> word;

  cout << Solution().countOfSubstrings(word, k) << '\n';
}
