class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int profit = 0;

        for(int i = 0; i< n; i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }else{
                profit = max(profit , prices[i] - minPrice);
            }
        }

        return profit;
    }
};