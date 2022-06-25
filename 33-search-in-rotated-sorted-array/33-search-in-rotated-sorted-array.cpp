class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            bool leftHalfSorted = nums[low] <= nums[mid];
            bool existsInLeftHalf = nums[low] <= target && nums[mid] >= target;
            bool existsInRightHalf = nums[mid] <= target && nums[high] >= target;
            
            if(leftHalfSorted){
                if(existsInLeftHalf)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            
            else{
                if(existsInRightHalf)
                    low = mid + 1;
                else 
                    high = mid - 1;
            }
        }
        return -1;
    }
};