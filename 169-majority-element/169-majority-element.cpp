class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> map;
        for(auto it : nums) map[it]++;
        for(auto it : map){
            if(it.second > nums.size()/2)
                return it.first;
        }
        return -1;
        
        
        
        
        
        
        
        
        
        // int count = 0, n = nums.size() - 1;
        // for(int i = 0; i < n; i++){
        //     count = 1;
        //     for(int j = 0; j < n; j++){
        //         if(nums[i] == nums[j])
        //             count++;
        //     }
        //     if(count > nums.size()/2)
        //         return nums[i];
        // }
        // return -1;
    }
};