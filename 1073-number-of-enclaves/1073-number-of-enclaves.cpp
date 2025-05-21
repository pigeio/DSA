class Solution {
public:
    typedef pair<int,int>p;
    vector<vector<int>>directions{{-1,0}, {0, 1} ,{1,0 }, {0,-1}};

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<p>que;

        for(int i=0;i<n;i++){
            if(grid[i][0] == 1){
                grid[i][0] = 0;
                que.push({i, 0});
            }
            if(grid[i][m-1] == 1){
                grid[i][m-1] = 0;
                que.push({i,m-1});
            }
        }

        for(int j = 0;j<m;j++){
            if(grid[0][j] == 1){
                grid[0][j] = 0;
                que.push({0 , j});
            }
            if(grid[n-1][j] == 1){
                grid[n-1][j] = 0;
                que.push({n-1, j});
            }
        }

        
        while(!que.empty()){
            p curr = que.front();
            que.pop();

            int r = curr.first;
            int c = curr.second;

            for(auto &dir : directions){
                int new_r = r + dir[0];
                int new_c = c + dir[1];

                if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && grid[new_r][new_c] == 1){
                    grid[new_r][new_c] = 0;
                    que.push({new_r , new_c});
                }
            }
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};