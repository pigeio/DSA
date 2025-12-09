class Solution {
public:
    int n;
    int solve(vector<int>& prices , int i , int buy , int transaction, vector<vector<vector<int>>>& dp){
        if(i == n || transaction == 0)return 0;
        if(dp[i][buy][transaction] != -1){
            return dp[i][buy][transaction];
        }
        if(buy == 1){
            return dp[i][buy][transaction] = max(-prices[i] + solve(prices , i+1 , 0 , transaction ,dp) ,
            0 + solve(prices , i+1 , 1 , transaction , dp));
        }else{ //sell
            return dp[i][buy][transaction] = max(prices[i] + solve(prices , i+1 , 1 ,transaction-1 ,dp) ,
            0 + solve(prices , i+1 , 0 , transaction , dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(2 , vector<int>(3 , -1)));
        return solve(prices, 0 , 1, 2, dp);
    }
};