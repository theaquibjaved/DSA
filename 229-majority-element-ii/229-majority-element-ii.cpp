class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> temp;
        
        for(int i = 0; i < n; i++){
            temp[nums[i]]++;
        }
        
        vector<int> ans;
        for(auto it : temp){
            if(it.second > (n/3))
                ans.push_back(it.first);
        }
                 
        return ans;
        
    }
};