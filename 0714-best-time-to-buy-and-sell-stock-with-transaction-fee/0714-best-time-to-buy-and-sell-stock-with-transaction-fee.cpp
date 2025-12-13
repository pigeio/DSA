class Solution {
public:
    int n;
    int solve(vector<int>& prices, int fee , int i , int buy ,vector<vector<int>>& dp){
        if(i == n)return 0;

        if(dp[i][buy] != -1){
            return dp[i][buy];
        }

        if(buy == 1)return dp[i][buy] = max(-prices[i] + solve(prices , fee , i+1 , 0 ,dp),
        0 + solve(prices , fee , i+1 , 1 ,dp));
        else{
            return dp[i][buy] = max((prices[i]- fee) + solve(prices , fee , i+1 , 1 , dp),
            0 + solve(prices , fee , i+1 , 0 , dp));
        }

    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        int i = 0, j = 1;

        vector<vector<int>>dp(n , vector<int>(2 , -1));
        return solve(prices , fee , i ,j ,dp);
    }
};