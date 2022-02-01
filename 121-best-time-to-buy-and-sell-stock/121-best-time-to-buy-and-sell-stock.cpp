class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currProfit = 0;
        int overallProfit = 0;
        int lowestStock = 10e4 + 1;
        for (int i = 0; i < prices.size(); ++i)
        {
            lowestStock = min(prices[i], lowestStock);
            currProfit = prices[i] - lowestStock;
            overallProfit = max(currProfit, overallProfit);
        }
        return overallProfit;
    }
};