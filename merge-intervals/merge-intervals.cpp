class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
                
        vector<vector<int>> mergedIntervals;
        //edge case
        int n = intervals.size();
        if(n == 0)
            return mergedIntervals;
        
        sort(intervals.begin(), intervals.end());
        vector<int> temp;
        temp = intervals[0];
        
        for(auto it : intervals){
                if(it[0] <= temp[1])
                   temp[1] = max(temp[1], it[1]);                                
                else{
                    mergedIntervals.push_back(temp);
                    temp = it;
                }
        }
    
        mergedIntervals.push_back(temp);
        return mergedIntervals;
        
    }
};