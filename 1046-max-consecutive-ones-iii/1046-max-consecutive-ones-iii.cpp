class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0;
        int l = 0 , r = 0;
        int maxLength = 0;
        int n = nums.size();
        while(r < n){
            if(nums[r] == 0){
                zero++;
            }while(zero > k){ // agar zero k se jayada ho jata hai toh l ko aage badha do 
                if(nums[l] == 0){
                    zero--;
                }
                l++;
            }
            if(zero <= k){
                int length = r-l+1;
                maxLength = max(maxLength , length);
                r++;
            }
            
        }
        return maxLength;
    }
};