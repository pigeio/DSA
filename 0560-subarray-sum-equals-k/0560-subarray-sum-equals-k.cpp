class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int cumSum = 0;
        int result = 0;
        mp.insert({0 , 1});

        for(int i = 0; i< n; i++){
            cumSum += nums[i];
            if(mp.find(cumSum - k) != mp.end()){
                result += mp[cumSum-k];
            };
            mp[cumSum]++;
        }

        return result;
    }
};