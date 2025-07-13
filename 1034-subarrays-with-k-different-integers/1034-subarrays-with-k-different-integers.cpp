class Solution {
public:
    int niceSubarray(vector<int>& nums, int k){
        unordered_map<int , int>mp;
        int l = 0 , r = 0;
        int result = 0;
        int n = nums.size();

        while(r < n){
            mp[nums[r]] += 1;
            while(mp.size() > k){
                mp[nums[l]] -= 1;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            result += r-l+1;
            r++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return niceSubarray(nums , k) - niceSubarray(nums , k-1);
    }
};