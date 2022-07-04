class Solution {
public:
    int mySqrt(int x) {
         int low = 0;
         int high = x;
        long long int mid;
        int ans = -1;
        
        if(x<2) return x;
        
        while(low <= high){
            mid = low + (high - low)/2;
            long long int sq = mid * mid;
                  
            if(sq == x)
                   return mid;
            else if (sq < x){
                ans = mid;
                low = mid + 1;
            }
                   
            else
                   high = mid - 1;
        }
        return ans;
    }
};