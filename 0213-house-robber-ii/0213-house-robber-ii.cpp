class Solution {
public:
    int t[101];
    int solve(vector<int>& nums , int curr,  int n){
        if(curr > n) return 0;

        if(t[curr] != -1){
            return t[curr];
        }

        int steal = nums[curr] + solve(nums , curr+2 , n);
        int skip = solve(nums , curr+1 , n);

        return t[curr] = max(steal ,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)return nums[0];

        if(n == 2) return max(nums[0] , nums[1]);

        memset(t , -1, sizeof(t));

        //case-1
        int take_0th_index_house = solve(nums , 0 ,n-2);

        memset(t,-1 , sizeof(t));
        //case-2
        int take_1st_index_house = solve(nums , 1, n-1);

        return max(take_0th_index_house , take_1st_index_house);
    }
};