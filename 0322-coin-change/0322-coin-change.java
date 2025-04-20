class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1); // Initialize with a value larger than possible
        dp[0] = 0; // Base case: 0 coins needed for amount 0
        
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
        }
        
        return dp[amount] > amount ? -1 : dp[amount];
    }

    // Main method for testing
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}       