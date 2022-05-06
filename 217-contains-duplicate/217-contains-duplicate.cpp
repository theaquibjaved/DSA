class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> m;
        for(auto n : nums) m[n]++;
        for(auto n : m){
            if(n.second > 1) return true;
        }
        
        return false;
        
        
        
        
        
        
        
        
        
        // sort(nums.begin(), nums.end()); // O(loog n)
        // for(int i = 0; i < nums.size()-1; i++){
        //     if(nums[i] == nums[i+1])
        //         return true;
        // }
        // return false;
        
    }
};