class Solution {
public:
    typedef pair<int,int>p;
    vector<vector<int>>directions{{-1 ,0}, {1,0},{0,-1},{0,1}};
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int n = board.size();
        int m = board[0].size();

        vector<vector<char>>result(n , vector<char>(m ,'O'));

        queue<p>que;
       for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') { 
                board[i][0] = '#';
                que.push({i, 0}); 
            }
            if (board[i][m - 1] == 'O') {
                board[i][m - 1] = '#';
                que.push({i, m - 1}); 
            }
        }

        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') {
                board[0][j] = '#';
                que.push({0, j}); 
            }
            if (board[n - 1][j] == 'O') {
                board[n - 1][j] = '#';
                que.push({n - 1, j}); 
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

                if(new_r >=0 && new_r <n && new_c >=0 && new_c <m && board[new_r][new_c] == 'O'){
                    board[new_r][new_c] = '#';
                    que.push({new_r , new_c});
                }                 
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};