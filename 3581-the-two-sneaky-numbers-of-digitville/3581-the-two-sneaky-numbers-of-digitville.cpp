class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>mp;
        vector<int>result;

        for(auto& num : nums){
            mp[num]++;

            if(mp[num] == 2){
                result.push_back(num);
            }
        }

        return result;
    }
};