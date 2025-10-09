class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1;
        sort(nums.begin() ,nums.end());
        int minVal = nums[0];
        

        for(int i = 0; i< n; i++){
            if(nums[i]-minVal > k){
                count++;
                minVal = nums[i];
            }
        }

        return count;
    }
};