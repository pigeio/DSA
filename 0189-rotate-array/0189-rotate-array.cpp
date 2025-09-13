class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int>sorted(n);

        for(int i = 0; i< k; i++){
            sorted[i] = nums[n-k+i];
        }

        for(int i = 0 ; i< n-k; i++){
            sorted[k+i] = nums[i];
        }

        nums = sorted;

    }
};