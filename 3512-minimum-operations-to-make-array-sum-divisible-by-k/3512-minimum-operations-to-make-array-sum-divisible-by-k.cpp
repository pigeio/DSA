class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin() , nums.end() , 0);
        int ans = 0;
        ans = sum % k;
        return ans;
    }
};