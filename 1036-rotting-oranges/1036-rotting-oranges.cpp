class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions{{-1,0} , {1,0} , {0,-1} , {0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<P> que;
        int freshCount = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m ; j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                }else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }
        int minute = 0;
        while(!que.empty()){
            int S = que.size();
            bool rottedThisTime = false;
            while(S--){
                P curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto &dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >=0 && new_j >=0 && new_i <n && new_j <m && grid[new_i][new_j] == 1){
                        grid[new_i][new_j] = 2;
                        que.push({new_i , new_j});
                        freshCount--;
                        rottedThisTime = true;
                    }
                }
            }
            if (rottedThisTime) minute++;
        }
        return freshCount == 0 ? minute : -1 ;
    }
};