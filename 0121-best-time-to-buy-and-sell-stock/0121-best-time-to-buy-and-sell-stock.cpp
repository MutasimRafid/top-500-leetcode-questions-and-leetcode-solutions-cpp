class Solution {
public:
    //solution 1: nested loop . TC: O(n)^2
    //solution 2: using min and only 1 loop
    //TC: O(n) SC: O(1)
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int currProfit = 0;
        int minPrice = INT_MAX;
        
        for(int i = 0;i<prices.size();i++){
            minPrice = min(minPrice,prices[i]);
            currProfit = prices[i] - minPrice;
            profit = max(profit,currProfit);
        }
        return profit;
    }
};