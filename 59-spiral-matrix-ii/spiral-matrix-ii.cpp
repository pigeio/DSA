class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int m = n;
        vector<vector<int>> matrix(m,vector<int>(n));
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        if (n==0){
            return {};
        }
        int id =0;
        int counter = 1;

        while(top<=bottom && left<=right){
            if(id==0){
                for(int i=left;i<=right; i++){
                    matrix[top][i] = counter++;
                }top++;
            }

            if(id==1){
                for(int i=top;i<=bottom;i++){
                    matrix[i][right] = counter++;
                }right--;
            }

            if(id==2){
                for(int i=right;i>=left;i--){
                    matrix[bottom][i] = counter++;
                }bottom--;
            }

            if(id==3){
                for(int i=bottom;i>=top;i--){
                    matrix[i][left] = counter++;
                }left++;
            }
            id = (id+1)%4;
        }return matrix;
    }
};