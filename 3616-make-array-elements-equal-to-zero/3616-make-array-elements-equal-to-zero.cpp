class Solution {
public:
    bool check(vector<int>&nums , int curr , int dir , int count){
        int i = curr;
        vector<int>temp = nums;
        while(i < nums.size() && i >= 0 && count > 0){
            if(temp[i] > 0){
                temp[i]--;
                dir *= -1;
                if(temp[i] == 0){
                    count--;
                }
            }
            i += dir;
        }
        return count == 0;
    }
    int countValidSelections(vector<int>& nums) {
        int result = 0; 
        int n = nums.size();

        int count = 0; //it takes count of non-zero

        for(int i = 0 ; i< n ; i++){
            if(nums[i] != 0){
                count++;
            }
        }

        for(int i = 0; i< n ; i++){
            if(nums[i] == 0){
                if(check(nums , i , -1 ,count)) //(nums,currnums,direction for left,count of zero numbers)
                result++;

                if(check(nums ,i , 1 , count))
                result++;
            }
        }

        return result;
    }
};