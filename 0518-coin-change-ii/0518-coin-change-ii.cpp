class Solution {
public:
    int n;
    int t[301][5001];
    int solve(int amount, vector<int>& coins, int i){
        if(amount == 0) return 1;

        if(i == n)return 0;
        if(t[i][amount] != -1){
            return t[i][amount];
        }

        if(amount < coins[i]){
            return solve(amount , coins , i+1);
        }

        int take = solve(amount- coins[i] ,coins ,i);
        int skip = solve(amount ,coins ,i+1);

        return t[i][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t , -1 , sizeof(t));
        return solve(amount , coins , 0);
    }
};