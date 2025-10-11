class Solution {
public:
    int n;
    typedef long long ll;
    unordered_map<ll , ll>mp;
    vector<ll>t;
    ll solve(vector<ll>& nums , int i){
        if(i >= n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }
        //skip
        ll skip = solve(nums , i+1);

        //take
        int j = lower_bound(nums.begin()+ i + 1 , nums.end() , nums[i] + 3) - nums.begin();
        ll take = nums[i]*mp[nums[i]] + solve(nums, j);

        return t[i] =  max(skip ,take);
    }
    long long maximumTotalDamage(vector<int>& power) {
        for(auto& x : power){
            mp[x]++;
        }

        vector<ll>nums;
        for(auto &it : mp){
            nums.push_back(it.first);
        }

        sort(nums.begin() , nums.end());
        n = nums.size();
        t.assign(n+1 , -1);

        return solve(nums , 0);
    }
};