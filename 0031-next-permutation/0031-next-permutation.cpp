class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int gola_element = -1;

        for(int i = n-1; i > 0; i--){
            if(nums[i-1] < nums[i]){
                gola_element = i-1;
                break;
            }
        }
        if(gola_element != -1){
            int just_greater = gola_element;
            for(int j = n-1; j > gola_element ; j--){
                if(nums[j] > nums[gola_element]){
                    just_greater = j;
                    break;
                }
            }

            swap(nums[gola_element], nums[just_greater]);
        }

        reverse(nums.begin() + gola_element+1 , nums.end());
    }
};