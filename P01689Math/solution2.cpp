class Solution {
public:
    int minPartitions(string n) {
        char m = '0';
        for (auto c : n) {
            if (c > m)
                m = c;
        }

        return m - '0';
    }
};