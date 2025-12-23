class Solution {
public:
    int n;
    int solve(vector<int>& nums , int s , int j, vector<vector<int>>& dp){
        if(s+1 == j)return 0;
        int ans = 0;

        if(dp[s][j] != -1){
            return dp[s][j];
        }

        for(int k = s+1; k < j; k++){
            int steps = nums[s]*nums[k]*nums[j] + solve(nums,s,k,dp) + solve(nums,k,j,dp);
            ans = max(ans ,steps);    
        }

        return dp[s][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin() , 1);
        nums.push_back(1);
        n = nums.size();
        vector<vector<int>>dp(n,  vector<int>(n , -1));
        return solve(nums , 0 , n-1,dp);
    }
};