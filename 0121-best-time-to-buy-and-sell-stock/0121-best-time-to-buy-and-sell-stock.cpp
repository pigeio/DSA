class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int prevPrice = INT_MAX;


        for(int i = 0; i < n ; i++){
            if(prices[i] < prevPrice){
                prevPrice = prices[i];
            }else{
                profit = max(profit, prices[i]- prevPrice);
            }
        }

        return profit;
    }
};