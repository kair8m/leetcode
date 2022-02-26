class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        vector<int> counts(amount, 0);
        return coinChange(coins, amount, counts);
    }
    
    int coinChange(vector<int>& coins, int amount, vector<int>& counts) {
        if (amount < 0)
            return -1;
        if (amount == 0)
            return 0;
        if (counts[amount - 1])
            return counts[amount - 1];
        int min = INT_MAX;
        for (const auto& coin : coins) {
            int res = coinChange(coins, amount - coin, counts);
            if (res >= 0 && res < min)
                min = res + 1;
        }
        counts[amount - 1] = min == INT_MAX ? -1 : min;
        return counts[amount - 1];
    }
};