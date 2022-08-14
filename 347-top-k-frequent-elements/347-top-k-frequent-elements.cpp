class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       if (nums.empty())
            return {};
        
        vector<int> topElement;
        vector<vector<int>> buckets(nums.size() + 1);
        
        unordered_map<int, int> numMap;
        
        for (int num : nums)
            numMap[num]++;
        for (auto it = numMap.begin(); it != numMap.end(); it++) 
            buckets[it->second].push_back(it->first);
        
        for (int i = buckets.size()-1; i >= 0; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                topElement.push_back(buckets[i][j]);
                
                if (topElement.size() == k)
                    return topElement;
            }
        }
        
        return topElement;
    }
};