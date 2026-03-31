class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        if (n == 1)
            return s1 == s2;
        string a1 = string(1, s1[0]);
        string a2 = string(1, s1[1]);
        string b1 = string(1, s2[0]);
        string b2 = string(1, s2[1]);

        for (int i = 2; i < n; i += 2) {
            a1 += s1[i];
            b1 += s2[i];
        }
        for (int i = 3; i < n; i += 2) {
            a2 += s1[i];
            b2 += s2[i];
        }
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());

        return a1 == b1 && a2 == b2;
    }
};