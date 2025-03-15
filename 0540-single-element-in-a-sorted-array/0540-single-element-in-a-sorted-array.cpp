class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0 , end = n-1;
        while(end > start){
            int mid = start + (end-start)/2;
            bool isEven;

            if((end-mid)%2 == 0){
                isEven = true;
            }else{
                isEven = false;
            }

            //check bagal wala element
            if(nums[mid] == nums[mid+1]){
                if(isEven){
                    start = mid+2;
                }else{
                    end = mid-1;
                }
            }else{// nums[mid] != nums[mid+1]
                if(isEven){
                    end = mid;
                }else{
                    start = mid+1;
                }

            }

        }return nums[end];
    }
};