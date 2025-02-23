class Solution {
public:
    int findRightmost(vector<int>& nums, int target,int n){
        int start = 0 , end = n-1;
        int Right_most = -1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(target < nums[mid]){
                end = mid-1;
            }else if(target > nums[mid]){
                start = mid+1;
            }else{
                Right_most = mid;
                start = mid+1;
            }
        }return Right_most;
    }

    int findLeftmost(vector<int>& nums, int target,int n){
        int start = 0 , end = n-1;
        int Left_most = -1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(target < nums[mid]){
                end = mid-1;
            }else if(target > nums[mid]){
                start = mid+1;
            }else{
                Left_most = mid;
                end = mid-1;
            }
        }return Left_most;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int Left_most = findLeftmost(nums,target,n);
        int Right_most = findRightmost(nums,target,n);

        return{Left_most , Right_most};
    }
};