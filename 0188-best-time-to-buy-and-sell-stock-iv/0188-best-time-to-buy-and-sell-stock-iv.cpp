class Solution {
public:
    int n;
    int solve(int k, vector<int>& prices ,int i , int kharidna , vector<vector<vector<int>>>& dp){
        if(k == 0 || i == n)return 0;

        if(dp[i][kharidna][k] != -1){
            return dp[i][kharidna][k];
        }
        //buy
        if(kharidna == 1)return dp[i][kharidna][k] = max(-prices[i] + solve(k , prices,i+1 ,0 , dp) ,
        0 + solve(k , prices , i+1 , 1 , dp));
        else{ //sell
            return dp[i][kharidna][k]= max(prices[i] + solve(k-1 , prices , i+1 , 1 , dp),
            0 + solve(k ,prices ,i+1 , 0 , dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
        int i = 0 ,j = 1;
        return solve(k , prices , i , j ,dp);
    }
};