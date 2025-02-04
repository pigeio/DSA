class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int>mp;
        int n = nums.size();

        for(int &num : nums){
            mp[num]++;

            if(mp[num] > n/2){
                return num;
            }
        }
        return -1;


       
    }
};