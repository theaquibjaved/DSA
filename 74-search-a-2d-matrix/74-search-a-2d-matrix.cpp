class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        if(row == 0) return false; //edge case
        
        int low = 0;
        int high = (row*col) - 1;
        
        while(low <= high){
            
            int mid = (low + (high - low)/2);
            int mid_val = matrix[mid/col][mid%col];
            
            if(mid_val == target)
                return true;
            
            if(mid_val < target)
                low = mid + 1;
            
            else
                high = mid - 1;
        }
        
        return false;
    }
};