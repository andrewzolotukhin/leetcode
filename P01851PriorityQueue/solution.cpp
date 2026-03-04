class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {
        vector<int> qq = queries;
        sort(qq.begin(), qq.end());
        sort(intervals.begin(), intervals.end());
        priority_queue<vector<int>> pq;

        int i = 0, n = intervals.size();
        unordered_map<int, int> r;
        for (auto q : qq) {
            while (i < n && intervals[i][0] <= q) {
                pq.push(
                    {intervals[i][0] - intervals[i][1] - 1, intervals[i++][1]});
            }

            while (pq.size() && pq.top()[1] < q)
                pq.pop();

            r[q] = pq.size() ? -pq.top()[0] : -1;
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
            ans.push_back(r[queries[i]]);

        return ans;
    }
};