class Solution {
public:
    bool solve(vector<vector<char>>& board , int sr , int er , int sc , int ec){
        unordered_set<char>st;

        for(int i = sr; i<= er ; i++){
            for(int j = sc; j <= ec ; j++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end())
                return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {

        //for rows

        for(int r = 0; r < 9 ; r++){
            unordered_set<char>st;
            for(int c = 0; c < 9; c++){
                if(board[r][c] == '.') continue;
                if(st.find(board[r][c]) != st.end()){
                    return false;
                }
                st.insert(board[r][c]);
            }
        }

        //for columns

        for(int c = 0;c < 9; c++){
            unordered_set<char>st;
            for(int r = 0; r<9;r++){
                if(board[r][c] == '.') continue;
                if(st.find(board[r][c]) != st.end()){
                    return false;
                }
                st.insert(board[r][c]);
            }
        }

        //for 3*3 matrix

        for(int sr=0 ; sr< 9; sr += 3){
            int er = sr+2;
            for(int sc = 0 ; sc < 9; sc += 3){
                int ec = sc+2;

                if(!solve(board ,sr ,er ,sc , ec))
                return false;
            }
        }
        return true;
    }
};