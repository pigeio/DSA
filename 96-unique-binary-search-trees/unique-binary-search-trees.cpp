class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        int result = 0;
        for(int i=1; i<=n; i++){
            result += solve(i-1 , dp) * solve(n-i , dp);
        } return dp[n] = result;
    }
    int numTrees(int n) {
        vector<int> dp(n+1, -1);

        return solve(n,dp);
    }
};