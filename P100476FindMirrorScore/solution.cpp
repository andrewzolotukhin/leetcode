class Solution {
public:
  long long calculateScore(string s) {
    long long result = 0;
    unordered_map<int, vector<int>> freq;

    for (int i = 0; i < s.size(); i++) {
      char inversed = 'z' - s[i] + 'a';
      if (freq.count(inversed)) {
        freq[inversed].push_back(i);
      } else {
        freq[inversed] = {i};
      }
    }

    vector<bool> marked = vector<bool>(s.size(), false);

    for (int i = 0; i < s.size(); i++) {
      if (marked[i] || (!freq.count(s[i])))
        continue;

      int last = freq[s[i]].size() - 1;

      int currentStart = 0;
      int currentEnd = last;

      char inversed = 'z' - s[i] + 'a';
      if (freq[s[i]][currentEnd] >= i) {
        while (currentStart < currentEnd) {
          int mid = currentStart + (currentEnd - currentStart) / 2;
          if (mid == currentStart) {
            if (freq[s[i]][currentEnd] >= i) {
              currentEnd--;
            }
            break;
          }
          if (freq[s[i]][mid] >= i) {
            currentEnd = mid;
          } else {
            currentStart = mid;
          }
        }

        while (currentEnd >= 0 && marked[freq[s[i]][currentEnd]]) {
          freq[s[i]].erase(freq[s[i]].begin() + currentEnd);
          currentEnd--;
        }

        if (currentEnd < 0) {
          continue;
        }

        if (freq[s[i]][currentEnd] >= i) {
          continue;
        }
      }

      if (currentEnd < 0 || freq[s[i]][currentEnd] >= i) {
        continue;
      }

      if (marked[freq[s[i]][currentEnd]]) {
        freq[s[i]].erase(freq[s[i]].begin() + currentEnd);
        continue;
      }

      marked[i] = true;
      marked[freq[s[i]][currentEnd]] = true;
      result += (i - freq[s[i]][currentEnd]);
      freq[s[i]].erase(freq[s[i]].begin() + currentEnd);
    }

    return result;
  }
};