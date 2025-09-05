class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int curr , int n){
        if(curr >= n)return 0;;

        if(t[curr] != -1){
            return t[curr];
        }
        
        int steal = nums[curr] + solve(nums , curr+2, n);
        int skip = solve(nums, curr+1 , n);

        return t[curr] = max(steal , skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t , -1,  sizeof(t));
        return solve(nums, 0 , n);
    }
};