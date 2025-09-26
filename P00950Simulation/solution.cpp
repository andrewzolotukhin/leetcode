class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int> &deck) {
    sort(deck.begin(), deck.end());
    queue<int> q;
    for (int i = 0; i < deck.size(); i++) {
      q.push(i);
    }

    vector<int> ans(deck.size());

    for (int i = 0; i < deck.size(); i++) {
      ans[q.front()] = deck[i];
      q.pop();

      if (!q.empty()) {
        q.push(q.front());
        q.pop();
      }
    }
    return ans;
  }
};
