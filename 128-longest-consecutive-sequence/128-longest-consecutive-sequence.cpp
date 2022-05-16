class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for(int num : nums)
            hashSet.insert(num);
        
        int longestStreak = 0;
        
        for(int num : nums){
            if(!hashSet.count(num -1)){
                
                int y = num + 1;
                
                while(hashSet.count(y))
                    y += 1;
                
                longestStreak = max(longestStreak, y - num);
            }
        }
        return longestStreak;
    }
};