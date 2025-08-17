class Solution {
private:
  // slow
  void solve_dfs(vector<vector<int>> &people, vector<int> &currSkills,
                 unordered_set<int> &selected,
                 unordered_set<int> &currentPeople, int left,
                 unordered_set<int> &ans) {
    if (ans.size() != 0 && currentPeople.size() >= ans.size())
      return;
    if (left == 0) {
      ans.clear();
      for (auto s : currentPeople)
        ans.insert(s);
      return;
    }

    for (int i = 0; i < people.size(); i++) {
      if (currentPeople.count(i))
        continue;
      bool hasNew = false;
      for (int j = 0; j < people[i].size(); j++) {
        if (currSkills[people[i][j]] == 0) {
          hasNew = true;
          break;
        }
      }
      if (!hasNew)
        continue;

      int k = 0;
      for (int j = 0; j < people[i].size(); j++) {
        currSkills[people[i][j]]++;
        if (currSkills[people[i][j]] == 1) {
          k++;
          selected.insert(people[i][j]);
        }
      }
      currentPeople.insert(i);
      solve_dfs(people, currSkills, selected, currentPeople, left - k, ans);
      currentPeople.erase(i);

      for (int j = 0; j < people[i].size(); j++) {
        if (--currSkills[people[i][j]] == 0) {
          selected.erase(people[i][j]);
        }
      }
    }
  }

public:
  vector<int> smallestSufficientTeam(vector<string> &req_skills,
                                     vector<vector<string>> &people) {
    unordered_map<string, int> sid;
    for (int i = 0; i < req_skills.size(); i++) {
      sid[req_skills[i]] = i;
    }

    vector<int> masks;

    for (auto person : people) {
      int m = 0;
      for (auto skill : person) {
        int bit = 1 << sid[skill];
        m |= bit;
      }
      masks.push_back(m);
    }

    unordered_map<int, vector<int>> dp;
    dp[0] = {};

    for (int i = 0; i < people.size(); i++) {
      int mask = masks[i];
      if (mask == 0)
        continue;

      auto dpCopy = dp;
      for (auto &entry : dpCopy) {
        int oldMask = entry.first;
        int newMask = oldMask | mask;
        if (dp.find(newMask) == dp.end() ||
            dp[newMask].size() > entry.second.size() + 1) {
          dp[newMask] = entry.second;
          dp[newMask].push_back(i);
        }
      }
    }

    int fullMask = (1 << req_skills.size()) - 1;
    return dp[fullMask];

    /*
    vector<vector<int>> p;
    for(auto person: people) {
        vector<int> r;
        for(auto skill: person) {
            r.push_back(sid[skill]);
        }
        p.push_back(r);
    }

    vector<int> curr(req_skills.size(), 0);
    unordered_set<int> ans;
    unordered_set<int> selected, currentPeople;
    int left = req_skills.size();

    solve(p, curr, selected, currentPeople, left, ans);

    return vector<int>(ans.begin(), ans.end());
    */
  }
};
