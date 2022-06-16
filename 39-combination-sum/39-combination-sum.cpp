class Solution {
public:
    void findCombination(int i, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        if(i == arr.size()){
            if(target == 0)
                ans.push_back(ds);
        return;
        }
        
        //pickup:
        if(arr[i] <= target){
            ds.push_back(arr[i]);
            findCombination(i, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
        
        //not pickup:
        findCombination(i+1, target, arr, ans, ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;        
    }
};