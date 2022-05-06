class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
       // MOORE'S VOTING ALGORITHM
        int count = 0;
        int candidate = 0;
        
        for(int num : nums){
            if(count == 0){
                candidate = num;
            }
                
            if(num == candidate) count += 1;
            else count -= 1;
        }
        
        return candidate;
        
//          int count = 0;
//         int candidate = 0;

//         for (int num : nums) {
//             if (count == 0) {
//                 candidate = num;
//             }
//             if(num==candidate) count += 1; 
//             else count -= 1; 
//         }

//         return candidate;
        
        //--------------------
        // unordered_map<int, int> map;
        // for(auto it : nums) map[it]++;
        // for(auto it : map){
        //     if(it.second > nums.size()/2)
        //         return it.first;
        // }
        // return -1;
        // // TC: O(N)
        // // SC: O(N)
        
        //------------
        
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