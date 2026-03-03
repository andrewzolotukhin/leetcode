class Solution {
public:
    int minFlips(string target) {
        int ans = 0, n = target.size(), i = 0;
        while (i < n && target[i] == '0')
            i++;
        if (i == n)
            return ans;
        ans = 1;
        i++;
        while (i < n) {
            if (target[i] != target[i - 1]) {
                ans++;
            }
            i++;
        }
        return ans;
    }
};