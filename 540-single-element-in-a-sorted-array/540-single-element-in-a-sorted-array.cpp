class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int ele = 0;
        for(auto it : nums)
            ele = ele ^ it;
        return ele;
    }
};