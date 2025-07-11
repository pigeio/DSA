class Solution {
public:
    int calculateOdd(vector<int>& nums, int k){
        int n = nums.size();
        if(n < k) return 0;
        int l = 0  , r = 0;
        int countOdd = 0;
        int result = 0;


        while(r < n){
            if(nums[r] % 2 == 1){
                countOdd++;
            }
            while(countOdd > k){
                if(nums[l] % 2 == 1){
                    countOdd--;
                }
                l++;
            }
            result += r-l+1;
            r++;
        }
        return result;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return calculateOdd(nums , k) - calculateOdd(nums , k-1);
    }
};