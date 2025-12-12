class Solution {
public:
    int n;
    int solve(vector<int>& prices , int i ,int buy , vector<vector<int>>& dp){
        if(i >= n)return 0;
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        if(buy == 1){return dp[i][buy] = max(-prices[i] + solve(prices , i+1 , 0 , dp), //buy
        0 + solve(prices,  i+1 , 1 , dp)); // yaha pe av tak buy nhi hua hai isliye buy = 1
        }else{ //sell
            return dp[i][buy] = max(prices[i] + solve(prices , i+2 ,1 , dp),
            0 + solve(prices , i+1 , 0 , dp)); //yaha pe sell nhi hua hai toh buy kaise hoga so buy = 0
        }
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2 , -1));
        int i = 0 , j = 1;
        return solve(prices , i ,j , dp);
    }
};