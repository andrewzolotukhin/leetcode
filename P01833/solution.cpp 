class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001, 0);

        for (int cost : costs) {
            freq[cost]++;
        }

        int count = 0;

        for (int cost = 1; cost <= 100000; cost++) {
            int canBuy = min(freq[cost], coins / cost);

            count += canBuy;
            coins -= canBuy * cost;
        }

        return count;
    }
};