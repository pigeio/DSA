class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_r = 0;
        for(int &num : nums){
           xor_r ^= num;
        }

        int mask = (xor_r & (-xor_r)); // it gives you a digit through which you can differentiate
        int groupA = 0;
        int groupB = 0;

        for(auto & it:nums){
            if(it & mask){
                groupA ^= it;
            }else{
                groupB ^= it;
            }
        }
        return {groupA , groupB};
    }
};