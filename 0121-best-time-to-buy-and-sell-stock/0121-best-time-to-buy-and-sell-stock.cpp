class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MAX;
        int maxProfit = 0;

        for(auto i : prices){
            ans = min(ans, i);
            maxProfit = max(maxProfit , i - ans);
        }

        return maxProfit;
    }
};