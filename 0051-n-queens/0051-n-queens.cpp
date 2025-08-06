class Solution {
public:
    vector<vector<string>>result;
    int N ;

    bool isValid(vector<string>& board, int r , int c){
        //upward
        for(int i = r-1; i>=0 ; i--){
            if(board[i][c] == 'Q'){
                return false;
            }
        }

        //upward diagonal left
        for(int i = r-1,j = c-1 ; i >= 0 && j >= 0 ; i-- , j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        for(int i = r-1,j = c+1; i>=0 && j <N ; i-- , j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void solve(vector<string>& board, int r){
        if(r >= N){
            result.push_back(board);
            return;
        }

        for(int c = 0; c < N; c++){
            if(isValid(board ,r, c)){
                board[r][c] = 'Q';
                solve(board , r+1);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string>board(n , string(n, '.'));

        solve(board , 0);
        return result;
    }
};