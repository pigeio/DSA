class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int k=0; k<=31 ; k++){ // here k represents bit i.e 1st  , 2nd , .....
            int temp = (1 << k);
            int count0 = 0 , count1 = 0;
            for(auto &num : nums){
                if((num & temp) == 0){
                    count0 += 1;
                }else{
                    count1 += 1;
                }
            }
            if(count1 % 3 == 1){
                result = (result | temp);
            }
            
        }
        return result;
    }   
};