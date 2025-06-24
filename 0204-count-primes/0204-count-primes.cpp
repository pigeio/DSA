class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<int>ans(n , 1);
        for(int i = 2; i*i <= n; i++){
            if(ans[i]){
                for(int j = i*i; j<n ; j+=i){
                   ans[j] = 0;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n; i++){
            if(ans[i] == 1){
                count++;
            }
        }
        return count;
    }
};