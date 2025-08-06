class Solution {
public:
    vector<vector<int>>directions{{1,0} ,{-1,0},{0,1},{0,-1}};
    bool find(int i , int j, int idx, vector<vector<char>>& board, string word){
        if(idx == word.length())
        return true;

        if(i < 0 || j < 0 || i >= board.size() || j >=  board[0].size() || board[i][j] == '#') return false;

        if(board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        for(auto & dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(find(i_ , j_ , idx+1 , board , word))
            return true;
        }
        board[i][j] = temp; //backtrack
        return false;


    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i< n;i++){
            for(int j = 0; j < m ;j++){
                if(board[i][j] == word[0] && find(i , j , 0,board , word)){
                    return true;
                }
            }
        }
        return false;
    }
};