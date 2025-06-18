class Solution {
public:
  string predictPartyVictory(string senate) {
    queue<int> qr, qd;
    for (int i = 0; i < senate.size(); i++)
      senate[i] == 'R' ? qr.push(i) : qd.push(i);

    while (!qd.empty() && !qr.empty()) {
      auto r = qr.front(), d = qd.front();
      qr.pop();
      qd.pop();

      if (r < d) {
        qr.push(r + senate.size());
      } else {
        qd.push(d + senate.size());
      }
    }

    if (qr.size() > qd.size()) {
      return "Radiant";
    }

    return "Dire";
  }
};
