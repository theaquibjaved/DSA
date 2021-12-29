class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX, maxPr = 0, pr = 0;
        
        for(auto it : prices){
            minPrice = min(it, minPrice);
            pr = it - minPrice;
            maxPr = max(pr, maxPr);
        }
        
        return maxPr;
        
        
    }
};