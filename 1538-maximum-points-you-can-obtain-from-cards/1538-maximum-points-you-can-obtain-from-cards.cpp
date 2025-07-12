class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxSum = 0;
        int l_Sum = 0, r_sum = 0;
        for(int i = 0;i < k; i++){
            l_Sum += cardPoints[i];
        }
        maxSum = l_Sum;
        
        for(int i = 0 ; i < k; i++){
            l_Sum -= cardPoints[k-i-1];
            r_sum += cardPoints[n-i-1];
            maxSum = max(maxSum , l_Sum+r_sum);
        }
        return maxSum;
    }
};