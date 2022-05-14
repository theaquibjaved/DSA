
class Solution {
public:
       
    int uniquePaths(int m, int n) {
        int N = (m-1) + (n-1);
        int r = m - 1;
        double ans = 1;
        
        for(int i = 1; i <= r; i++)
            ans = ans * (N - r + i)/i;
        
        return (int) ans;
    }
};
//-------------------------------
//--------------------------------
// BETTER: DYNAMIC PROGRAMMINS:
// class Solution {
// public:
//     int countPaths(int i, int j, int m, int n){
//         if(i == (n-1) && j == (m-1))
//             return 1;
        
//         if(i >= n || j >= m)
//             return 0;
        
//         else
//             return countPaths(i+1, j, m, n) + countPaths(i, j+1, m, n);
//     }
    
//     int uniquePaths(int m, int n) {
        
//         int vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
//         if(m == 1 && n == 1)
//             retrun countPaths(0, 0, m, n, dp);
        
//         return dp[0][0];
//     }
// };