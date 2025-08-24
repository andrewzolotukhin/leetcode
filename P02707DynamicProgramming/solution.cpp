class Solution {
private:
  /*  void solve(string &s, int start, vector<string>& dict, vector<bool> &used,
    int &ans, int skipped) { if(skipped > ans) return; if(start >= s.size()) {
            ans = min(ans, skipped);
            return;
        }

        auto eq = [&](string &s, string &s2, int st) {
            for(int i = 0 ; i < s2.size(); i++) {
                if(s[st+i]!=s2[i]) return false;
            }
            return true;
        };

        for(int i= 0 ; i< dict.size(); i++) {
            if(used[i]) continue;
            if( s.size() >= dict[i].size() && eq(s, dict[i], start)) {
                used[i] = true;
                solve(s, start+dict[i].size(), dict, used, ans, skipped);
                used[i] = false;
            } else {
                solve(s, start+1, dict, used, ans, skipped+1);
            }
        }
    }*/
public:
  int minExtraChar(string s, vector<string> &dictionary) {
    /*
    vector<bool> used(dictionary.size(), false);
    int ans = s.size();

    solve(s, 0, dictionary, used, ans, 0);

    return ans;
    */

    // DP - the correct way
    int n = s.size();
    vector<int> dp(n + 1, 0);
    unordered_set dict(dictionary.begin(), dictionary.end());

    for (int i = n - 1; i >= 0; i--) {
      dp[i] = dp[i + 1] + 1;

      for (int j = 0; j <= n - i; j++) {
        if (dict.count(s.substr(i, j))) {
          dp[i] = min(dp[i], dp[i + j]);
        }
      }
    }

    return dp[0];
  }
};
