class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>> &languages,
                       vector<vector<int>> &friendships) {

    unordered_set<int> cannot;
    for (auto f : friendships) {
      unordered_map<int, int> mp;
      bool isGood = false;
      for (auto l : languages[f[0] - 1])
        mp[l] = 1;

      for (auto l : languages[f[1] - 1]) {
        if (mp[l] == 1) {
          isGood = true;
          break;
        }
      }
      if (isGood)
        continue;

      cannot.insert(f[0] - 1);
      cannot.insert(f[1] - 1);
    }

    int ans = 0;
    vector<int> c(n + 1, 0);

    for (auto f : cannot) {
      for (int l : languages[f]) {
        c[l]++;
        ans = max(ans, c[l]);
      }
    }

    return cannot.size() - ans;

    /*int m = languages.size();
    vector<int> parents(m);
    for(int i = 0; i < m; i++) parents[i] = i;

    function<int(int)> find = [&](int a) {
        if(parents[a] == a) return a;
        return parents[a] = find(parents[a]);
    };

    auto join = [&](int a, int b) {
        auto pa = find(a);
        auto pb = find(b);
        if(pa == pb) return;
        parents[pa] = pb;
    };

    for(int i = 0; i < friendships.size(); i++) {
        join(friendships[i][0]-1, friendships[i][1]-1);
    }

    unordered_map<int, int> sizes;
    unordered_map<int, map<int, int>> langs;

    for(int i = 0; i < m; i++) {
        int c = find(i);
        sizes[c]++;
        for(int j = 0; j < languages[i].size(); j++) {
            langs[c][languages[i][j]]++;
        }
    }

    int ans = 0;

    for(auto [c, cs]: sizes) {
        int mp = 0;
        bool found = false;
        for(int i = 0; i < n && !found; i++) {
            if(langs[c][i] == cs) {
                found = true;
            }
            mp = max(mp, langs[c][i]);
        }
        if(found) continue;
        ans += cs - mp;
    }

    return ans;*/
  }
};
