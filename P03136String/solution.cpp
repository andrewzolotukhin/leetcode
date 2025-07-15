class Solution {
private:
  bool isVovel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }

public:
  bool isValid(string word) {
    int n = word.size();
    if (n < 3)
      return false;

    int vovels = 0, consonants = 0;
    int digits = 0;

    for (int i = 0; i < n; i++) {
      if (word[i] == '@' || word[i] == '#' || word[i] == '$')
        return false;
      if (word[i] >= '0' && word[i] <= '9') {
        digits++;
      } else {
        if (isVovel(word[i])) {
          vovels++;
        } else {
          consonants++;
        }
      }
    }

    return vovels > 0 && consonants > 0 && vovels + consonants + digits == n;
  }
};
