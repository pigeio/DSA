class Solution {
public:
    int n;
    int t[2501][2501];
    int solve(vector<int>& nums , int i ,int j){
        if(j == n)return 0;
        if(t[j][i+1] != -1){
            return t[j][i+1];
        }
        int nottake = solve(nums , i , j+1);

        int take = 0;
        if(i == -1 || nums[j] > nums[i]){
            take = 1 + solve(nums , j, j+1);
        }

        return t[j][i+1] = max(take , nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(t , -1 , sizeof(t));
        return solve(nums , -1 , 0 );
    }
};