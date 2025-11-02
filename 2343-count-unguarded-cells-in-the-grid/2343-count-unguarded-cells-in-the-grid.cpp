class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m , vector<int>(n , 0));

        for(vector<int>& vec: walls){
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 2;
        }

        for(vector<int>& vec: guards){
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 3;
        }

        for(vector<int>& gaurd : guards){
            int i = gaurd[0];
            int j = gaurd[1];
            markguard(i , j , grid);
        }

        int count = 0;
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    count++;
                }
            }
        }

        return count;
    }

    void markguard(int r , int c , vector<vector<int>>& grid){
        //UP
        for(int i = r-1; i >= 0; i--){
            if(grid[i][c] == 2 || grid[i][c] == 3){
                break;
            }
            grid[i][c] = 1;
        }

        //DOWN
        for(int i = r+1; i < grid.size(); i++){
            if(grid[i][c] == 2 || grid[i][c] == 3){
                break;
            }
            grid[i][c] = 1;
        }

        //LEFT
        for(int j = c-1; j >= 0; j--){
            if(grid[r][j] == 2 || grid[r][j] == 3){
                break;
            }
            grid[r][j] = 1;
        }

        //RIGHT
        for(int j = c+1; j < grid[0].size(); j++){
            if(grid[r][j] == 2 || grid[r][j] == 3){
                break;
            }
            grid[r][j] = 1;
        }
    }
};