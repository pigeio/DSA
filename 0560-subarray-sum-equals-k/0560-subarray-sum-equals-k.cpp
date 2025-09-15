class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int count = 0;

        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        mp[0] = 1; // handles subarrays starting at index 0

        for (int j = 0; j < n; j++) {
            int val = prefixSum[j] - k;
            if (mp.find(val) != mp.end()) {
                count += mp[val];
            }
            mp[prefixSum[j]]++;
        }

        return count;
    }
};

