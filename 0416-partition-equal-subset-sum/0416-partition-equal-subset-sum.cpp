class Solution {
public:
    int n;
    bool solve(vector<int>& nums , int idx , int x ,  vector<vector<int>>& t){
        if(x == 0)return true;
        if(idx >= n-1)return false;

        if(t[idx][x] != -1){
            return t[idx][x];
        }
        

        bool taken = false;
        if(nums[idx] <= x){
            taken = solve(nums , idx+1, x-nums[idx] , t);
        }

        bool notTaken = solve(nums , idx+1 , x  , t);

        return t[idx][x] = taken || notTaken;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        
        int s = accumulate(nums.begin() , nums.end() , 0);

        if(s%2 != 0){
            return false;
        }
        int x = s/2;
        vector<vector<int>>t(n+1 , vector<int>(x+1 , -1));
        return solve(nums , 0 , x , t);
    }
};