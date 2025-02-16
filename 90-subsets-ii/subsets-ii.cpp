class Solution {
public:
    void solve(vector<int>& nums,  vector<int>& temp, vector<vector<int>>& result ,int i){
        int l = nums.size();

        //base case
        if(i >= l){
            result.push_back(temp);
            return;
        }

        //recurrsion

        temp.push_back(nums[i]);//when you decide to take the next element 
        solve(nums,temp,result,i+1);
        temp.pop_back();//when you decide to not take the next element 
         while(i<l-1 && nums[i] == nums[i+1]){//remove duplicates
            i++;
        }
        solve(nums,temp,result,i+1);

        
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        solve(nums,temp,result,0);
        return result;
    }
};