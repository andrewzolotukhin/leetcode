class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> rows(n, 0), cols(m, 0);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (mat[j][k]) {
                    rows[j]++;
                    cols[k]++;
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (mat[j][k] && rows[j] == 1 && cols[k] == 1) {
                    ans++;
                }
            }
        }
        return ans;
    }
};