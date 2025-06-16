class Solution {
public:
    double solve(double y , long m){
        if(m == 0) return 1;
        if(m < 0){
            return solve(1/y,-m);
        }else if(m%2 == 0){
            return solve(y*y, m/2);
        }
        return y* solve(y*y , (m-1)/2);
        
    }
    double myPow(double x, int n) {
       
        return solve(x ,(long) n);
    }
};