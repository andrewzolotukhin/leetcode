class Solution {
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
    priority_queue<int> pq;
    for (auto c : candies)
      pq.push(c);

    vector<bool> ans(candies.size());
    for (int i = 0; i < candies.size(); i++) {
      ans[i] = (pq.top() <= (candies[i] + extraCandies));
    }
    return ans;
  }
};
