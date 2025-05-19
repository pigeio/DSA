class Solution {
public:
    typedef pair<int,int>p;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> result(n, vector<int>(m, -1));
        queue<p>que;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    que.push({i ,j});
                }
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


                if(new_r >=0 && new_r <n && new_c>=0 && new_c<m && result[new_r][new_c] == -1){
                    result[new_r][new_c] = result[r][c] + 1;
                    que.push({new_r , new_c});
                }
            }
        }
        return result;
    }
};