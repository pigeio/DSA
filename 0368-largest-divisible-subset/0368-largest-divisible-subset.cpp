class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        vector<int>subset(n , 1);
        vector<int>prevIdx(n ,-1);

        int maxL = 1;
        int last_chosen_index = 0;

        for(int i =1; i< n; i++){
            for(int j = 0; j< i; j++){
                if(nums[i] % nums[j] == 0){

                    if(subset[i] < subset[j]+1){
                        subset[i] = subset[j]+1;
                        prevIdx[i] = j;
                    }

                    if(subset[i] > maxL){
                        maxL = subset[i];
                        last_chosen_index = i;
                    }
                }
            }
        }
        vector<int>result;
        while(last_chosen_index != -1){
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prevIdx[last_chosen_index];
        }
        return result;
    }
    
    
};