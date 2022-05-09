class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> set;
        for(auto it : nums)
            set.insert(it);
        
        int i = 0;
        for(int x : set)
            nums[i++] = x;
            
        return set.size();
    }
};