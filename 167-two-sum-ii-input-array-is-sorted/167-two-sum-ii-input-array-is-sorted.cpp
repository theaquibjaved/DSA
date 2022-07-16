class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> res;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                res = {left + 1, right + 1};
                return res;
            } else if (numbers[left] + numbers[right] > target) {
                -- right;
            } else {
                ++ left;
            }
        } 
        return res;
    }
};