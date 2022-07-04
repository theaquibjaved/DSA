class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int time = 0, totalOranges = 0, madeRotten = 0;
        queue<pair <int, int>> rotten;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bool cellEmpty = grid[i][j] == 0;
                bool isRotten = grid[i][j] == 2;
                
                if(!cellEmpty) totalOranges++;
                if(isRotten) rotten.push({i, j});
            }
        }
        
        int dx[4] = {0, 0, 1 , -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            madeRotten += k;
            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    bool isValid = nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1;
                    if(isValid){
                        grid[nx][ny] = 2;
                        rotten.push({nx, ny});
                    }
                }
            }
            if(!rotten.empty())
                time++;
        }
        
        if(totalOranges == madeRotten)
            return time;
        
        return -1;
    }
};