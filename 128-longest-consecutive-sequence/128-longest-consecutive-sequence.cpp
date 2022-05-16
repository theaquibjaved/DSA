class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0 ){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 1;
        int maxCount = 1;
        int prev = nums[0];
        
        for(int i = 1; i < n; i++){
            
            if(nums[i] == prev+1)
                count++;
            else if(nums[i] != prev)
                count = 1;
            maxCount = max(count, maxCount);
            prev = nums[i];
        }
        
        return maxCount;
    }
};