class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int maxi = INT_MIN;
        int ansStart = -1;
        int ansEnd = -1;
        int start = 0;

        for(int i = 0 ; i<n ;i++){
            if(sum == 0) // whenever sum is 0 we have to take a new start
            start = i;
            sum  = sum + nums[i];

            if(sum > maxi){
                maxi = sum ;
                ansStart = start;
                ansEnd = i;
            }

            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
        
    }
};