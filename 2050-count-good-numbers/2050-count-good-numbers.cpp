class Solution {
public:
    int M = 1e9 + 7;
    int pow(long long a , long long b){
        if(b == 0) return 1;

        if(b % 2 == 0){
            return (long long)pow((a*a) % M ,b/2 ) % M;
        }
        return (long long)(a % M) * pow((a * a) % M ,( b-1)/2) % M;
    }
    int countGoodNumbers(long long n) {
        return(long long) pow(5 , (n+1)/2) * pow(4,  n/2) % M;
    }
};