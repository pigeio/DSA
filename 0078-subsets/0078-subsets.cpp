class Solution {
public:
    vector<vector<int>>result;
    void generate(int i, vector<int>& nums , vector<int>temp){
        if(i >= nums.size()){
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        generate(i+1, nums , temp);
        temp.pop_back();
        generate(i+1 , nums , temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        generate(0 , nums, temp);
        return result;
    }
};