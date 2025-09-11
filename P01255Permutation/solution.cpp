class Solution {
public:
  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    int n = words.size();
    unordered_map<char, int> freq;
    vector<unordered_map<char, int>> wfreq;
    for (auto c : letters)
      freq[c]++;
    for (auto w : words) {
      unordered_map<char, int> m;
      for (char c : w)
        m[c]++;
      wfreq.push_back(m);
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
      bool isOk = true;
      int s = 0;
      auto rfreq = freq;
      for (int j = 0; j < n && isOk; j++) {
        if ((i & (1 << j)) == 0)
          continue;

        for (char c : words[j]) {
          if (rfreq[c] < wfreq[j][c]) {
            isOk = false;
            break;
          }
        }
        if (!isOk)
          break;

        for (char c : words[j]) {
          rfreq[c]--;
          s += score[c - 'a'];
        }
      }
      if (!isOk)
        continue;
      ans = max(ans, s);
    }

    return ans;
    /*
    int n = words.size();
    unordered_set<char> lt(letters.begin(), letters.end());
    unordered_map<char, int> freq;
    vector<unordered_map<char,int>> wfreq;
    for(auto c: letters) freq[c]++;
    for(auto w: words) {
        unordered_map<char,int> m;
        for(char c: w) m[c]++;
        wfreq.push_back(m);
    }
    vector<pair<int, int>> scores;
    for(int i = 0 ; i < n; i++) {
        string w = words[i];
        int s = 0;
        for(auto l: w) {
            if(lt.count(l) == 0) {
                s = 0;
                break;
            }
            s+= score[l-'a'];
        }
        if(s) scores.push_back({s, i});
    }

    sort(scores.rbegin(), scores.rend());
    int ans = 0;

    for(int i = 0; i < scores.size(); i++) {
        int idx = scores[i].second;
        bool isOk = true;
        for(auto [c, cnt]: wfreq[idx]) {
            if(freq[c] < cnt) {
                isOk = false;
                break;
            }
        }

        if(!isOk) continue;

        for(auto [c, cnt]: wfreq[idx]) {
            freq[c]-=cnt;
        }
        ans+=scores[i].first;
    }

    return ans;
    */
  }
};
