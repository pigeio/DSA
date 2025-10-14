class Solution {
public:
    bool isIncreasing(vector<int>&nums , int s , int e){
        for(int i = s+1 ; i < e; i++){
            if(nums[i] <= nums[i-1]){
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int start = 0; start+2*k <= n ; start++){
            int first = isIncreasing(nums , start , start+k);
            int second = isIncreasing(nums , start+k , start+2*k);
            if(first == true && second == true){
                return true;
            }
        }
        return false;
    }
};