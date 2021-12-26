class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxi = INT_MIN, sum = 0, n = nums.size();
        
        for(auto it : nums){
            sum += it;
            maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
        }
        
        return maxi;
        
    }
};