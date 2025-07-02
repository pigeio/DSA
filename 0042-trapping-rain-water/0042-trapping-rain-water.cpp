class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>L_max(n , 0);
        vector<int>R_max(n , 0);
        int ans = 0;
        L_max[0] = height[0];
        R_max[n-1] = height[n-1];

        for(int i = 1; i<n;i++){
            L_max[i] = max(L_max[i-1] , height[i]);
        }
        for(int i = n-2; i>=0;i--){
            R_max[i] = max(R_max[i+1] , height[i]);
        }

        for(int i = 0;i<n;i++){
            ans += min(L_max[i],  R_max[i]) - height[i];
        }
        return ans;

    }
};