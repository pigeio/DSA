class Solution {
public:
    int climbStairs(int n) {

        //base case
        if(n<=2)
        return n;

        int firstStep = 1 ,secondStep = 2 , result = 0;
        for(int i = 3; i<=n ; i++){
            result = firstStep + secondStep;
            firstStep = secondStep;
            secondStep = result;
        }
        return secondStep;

    }
};