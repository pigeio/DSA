class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int currentLength = 0;
        int maxLength = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 1){
                currentLength++;
                maxLength = max(maxLength , currentLength);
            }else{
                currentLength = 0;
            }
        }
        return maxLength;
    }
};