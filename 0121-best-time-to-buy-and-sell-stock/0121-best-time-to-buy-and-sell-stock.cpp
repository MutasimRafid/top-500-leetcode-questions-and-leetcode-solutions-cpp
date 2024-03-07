class Solution {
public:
    int maxProfit(vector<int>& prices) {
       //Approach 1: use nested loop... TC: O(n^2)..SC: O(1)
        //Approach 2: Use sliding window .. TC: O(n).. SC: O(1)
        
        int maxPro = 0;
        int minPrice = INT_MAX;
        
        for(int i = 0;i<prices.size();i++){
            minPrice = min(minPrice,prices[i]);
            maxPro = max(maxPro,prices[i]-minPrice);
        }
        
        return maxPro;
    }
};