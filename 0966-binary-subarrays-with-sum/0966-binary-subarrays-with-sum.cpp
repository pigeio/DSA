class Solution {
public:
    int atmost(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int l = 0 , r = 0;
        int count = 0;
        int sum = 0;

        while(r < n){
            sum += nums[r];
            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) -atmost(nums, goal-1);
    }
};