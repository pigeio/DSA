class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int prevRun = 0;
        int currRun = 1;
        int k = 0;

        for(int i = 1 ; i< n ;i++){
            if(nums[i] > nums[i-1]){
                currRun++;

            }else{
                prevRun = currRun;
                currRun = 1;
            }
            k = max(k , currRun/2);
            k = max(k , min(currRun , prevRun));               
        }

        return k;
    }
};