class Solution {
public:
    void sortColors(vector<int>& nums) {
        // declaration 
        int zeros,ones,twos;
        // initillisation
        zeros=ones=twos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeros++;
            }
            else if(nums[i]==1){
                ones++;
            } 
            else{
                twos++;
            }  
        }
        // spread
        int i = 0;
        while(zeros--){
            nums[i]=0;
            i++;
        }
        while(ones--){
            nums[i]=1;
            i++;
        }
        while(twos--){
            nums[i]=2;
            i++;
        }

        
    }
};