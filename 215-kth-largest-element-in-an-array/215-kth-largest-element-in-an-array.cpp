class Solution {
public:
   int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        k = n - k;
        
        return quickSelect(nums, k, 0, n-1);
    }
    
    int quickSelect(vector<int>& nums, int k, int l, int r){
        int pivot = nums[r]; 
        int p = l;
        
        for(int i = l; i < r; i++){
             if(nums[i] <= pivot)
                 swap(nums[p++], nums[i]);            
        }
        
        swap(nums[p], nums[r]);
        
        if(p > k)
            return quickSelect(nums, k, l, p-1); 
        else if(k > p)
            return quickSelect(nums, k, p+1, r);
        else
            return nums[p];
    }
};