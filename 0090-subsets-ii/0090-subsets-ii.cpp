class Solution {
public:
    vector<vector<int>>result;
    void find(int idx , vector<int>& nums,vector<int>&storeH){
        
        result.push_back(storeH);
            
        

        for(int i =idx; i< nums.size() ; i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }

            storeH.push_back(nums[i]);
            find(i+1 ,nums, storeH);
            storeH.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>storeH;
        sort(nums.begin() , nums.end());
        find(0 ,nums, storeH);
        return result;
    }
};