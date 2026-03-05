class Solution {
public:
    int minOperations(string s) {
        char e = '0';
        int ans = INT_MAX, c = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != e) {
                c++;
            }
            e = e == '0' ? '1' : '0';
        }
        ans = min(ans, c);
        c = 0;
        e = '1';
        for (int i = 0; i < n; i++) {
            if (s[i] != e) {
                c++;
            }
            e = e == '0' ? '1' : '0';
        }
        ans = min(ans, c);
        return ans;
    }
};