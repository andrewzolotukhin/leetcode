class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for (int i = 1; i < n && k > s.length(); ++i) {
            s += '1';

            string temp = s;
            for (int j = temp.length() - 2; j >= 0; --j) {
                char invertedBit = (temp[j] == '1') ? '0' : '1';
                s += invertedBit;
            }
        }

        return s[k - 1];
    }
};