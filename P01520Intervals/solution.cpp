class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> start(26, n), end(26, -1);

        // find first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            start[c] = min(start[c], i);
            end[c] = i;
        }

        vector<pair<int,int>> intervals;

        // try to build minimal valid interval for each char
        for (int c = 0; c < 26; c++) {
            if (start[c] == n) continue;

            int L = start[c];
            int R = end[c];
            bool valid = true;

            for (int i = L; i <= R; i++) {
                int ch = s[i] - 'a';

                if (start[ch] < L) {
                    valid = false;
                    break;
                }

                R = max(R, end[ch]);
            }

            if (valid)
                intervals.push_back({L, R});
        }

        // sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> result;
        int lastEnd = -1;

        for (auto &[L, R] : intervals) {
            if (L > lastEnd) {
                result.push_back(s.substr(L, R - L + 1));
                lastEnd = R;
            }
        }

        return result;
    }
};