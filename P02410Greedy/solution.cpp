class Solution {
public:
  int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int p = players.size() - 1;
    int t = trainers.size() - 1;

    int ans = 0;

    while (p >= 0 && t >= 0) {
      if (trainers[t] >= players[p]) {
        ans++;
        t--;
      }
      p--;
    }

    return ans;
  }
};
