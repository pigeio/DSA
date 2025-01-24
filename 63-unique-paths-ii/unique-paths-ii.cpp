class Solution {
public:
    int m,n;
    int t[101][101];
    int solution(vector<vector<int>>& obstacleGrid,int i,int j){
        //base case
        if(i>=m || j>=n || obstacleGrid[i][j] == 1)
        return 0;

        
        if(t[i][j] != -1)
        return t[i][j];

        //moving condition
        if(i==m-1 && j==n-1){
            return 1;
        }

        int right = solution(obstacleGrid,i,j+1);
        int down = solution(obstacleGrid,i+1,j);

        return t[i][j] = right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size(); //row
        n = obstacleGrid[0].size(); //column 

        memset(t, -1 , sizeof(t));
        return solution(obstacleGrid,0,0);
    }
};