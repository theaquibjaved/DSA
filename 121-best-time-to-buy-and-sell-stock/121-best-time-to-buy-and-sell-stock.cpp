class Solution {
public:

    int maxProfit(vector<int>& prices) {
            int maxProfit = 0;
            int minPrice = INT_MAX;
            int curProfit;
            
            for(int i=0; i<prices.size(); i++){
                minPrice = min(prices[i], minPrice);
                curProfit = prices[i] - minPrice;
                maxProfit = max(curProfit, maxProfit);
            }
        return maxProfit;
        }
    
        
        
    
};