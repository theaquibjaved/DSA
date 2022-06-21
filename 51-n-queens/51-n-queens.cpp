class Solution {
public:
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag, int n){
        
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){
            
            bool notAttack = leftRow[row] == 0 && lowerDiag[row + col] == 0 
                                && upperDiag[n - 1 + col - row] == 0;
            if(notAttack){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;
                
                solve(col + 1, board, ans, leftRow, upperDiag, lowerDiag, n);
                
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;                
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board (n);
        string s (n, '.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        
        vector<int> leftRow(n,0), upperDiag(2*n - 1, 0), lowerDiag(2*n - 1, 0);
        solve(0, board, ans, leftRow, upperDiag, lowerDiag, n);
        return ans;
    }
};

//----------------
// BRUTE:::
// class Solution {
// public:
//     bool isSafe(int row, int col, vector<string> &board, int n){
        
//         int duprow = row;
//         int dupcol = col;
//         while(row >= 0 && col >= 0){
//             if(board[row][col] == 'Q'){
//                 return false;
//             } 
//             row--; col--;
//         }
        
//         row = duprow;
//         col = dupcol;
//         while(col >= 0){
//             if(board[row][col] == 'Q'){
//                 return false;
//             } 
//             col--;
//         }
        
//         row = duprow;
//         col = dupcol;
//         while(row < n && col >= 0){
//             if(board[row][col] == 'Q'){
//                 return false;
//             }
//             row++; col--;
//         }
        
//         return true;
//     }
    
//     void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
//         if(col == n){
//             ans.push_back(board);
//             return;
//         }
        
//         for(int row = 0; row < n; row++){
//             bool notAttack = isSafe(row, col, board, n);
            
//             if(notAttack){
//                 board[row][col] = 'Q';
//                 solve(col+1, board, ans, n);
//                 board[row][col] = '.';
//             }
//         }
//     }
    
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board (n);
//         string s (n, '.');
//         for(int i = 0; i < n; i++){
//             board[i] = s;
//         }
        
        
//         solve(0, board, ans, n);
//         return ans;
//     }
// };