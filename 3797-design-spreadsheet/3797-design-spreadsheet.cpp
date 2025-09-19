class Spreadsheet {
public:
    vector<vector<int>>grid;
    Spreadsheet(int rows) {
        grid.assign(rows , vector<int>(26 , 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] -'A';
        int row = stoi(cell.substr(1))-1;

        grid[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] -'A';
        int row = stoi(cell.substr(1))-1;

        grid[row][col] = 0;
        
    }

    int solve(string& S){
        if(isdigit(S[0])){
            return stoi(S);
        }

        int col = S[0] -'A';
        int row = stoi(S.substr(1))-1;

        return grid[row][col];
    }
    
    int getValue(string formula) {
        string S = formula.substr(1); // it started from the idx 1;
        int plusIndex = S.find('+');
        string left = S.substr(0 , plusIndex);
        string right = S.substr(plusIndex+1);

        return solve(left) + solve(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */