class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
//          return nums.size() > set<int>(nums.begin(), nums.end()).size();        

//         // TC: O(N)
//         // SC: O(N)
        
        
        
        
        
        
        
        
        sort(nums.begin(), nums.end()); // O(loog n)
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
        
    }
};