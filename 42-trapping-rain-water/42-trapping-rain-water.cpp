class Solution {
public:
    int trap(vector<int>& arr) {
        
        int n = arr.size();
        int left = 0, right = n-1;
        int maxLeft = 0, maxRight = 0, res = 0;
        
        while(left <= right){
            if(arr[left] <= arr[right]){                
                if(arr[left] >= maxLeft) maxLeft = arr[left];
                else res += maxLeft - arr[left];
                
                left++;
            }
            else{
                if(arr[right] >= maxRight) maxRight = arr[right];
                else res += maxRight - arr[right];
                
                right--;
            }
        }
        
        return res;
    }
};