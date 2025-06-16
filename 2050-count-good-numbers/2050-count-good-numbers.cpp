class Solution {
public:
    const int M = 1e9+7;
    long long pow(long long a , long long b){
        if(b == 0) return 1;
        // if b = even
        long long half = pow(a , b/2);
        long long result = (half * half) % M ;

        if( b % 2 == 1){
            result = (result * a) % M;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
       long long even = (n+1)/2; // if n is even 
       long long odd = n/2;      //if n is odd

       long long result = pow(5 , even) * pow(4 , odd) % M;
       return result;

    }
};