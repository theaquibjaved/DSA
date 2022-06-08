class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size(), count = 0, maxCount = 0;
        
        for(auto it : nums){
            
            if(it == 1)
            {
                count++;
                maxCount = max(count, maxCount);
            }    
            else 
                count = 0;
            
        }
        
        return maxCount;
    }
};