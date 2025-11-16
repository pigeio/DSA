class Solution {
public:
    int numSub(string s) {
        
        long long countOne = 0;
        long long result = 0;
        long long mod = 1e9 + 7;

        for(auto &i : s){
            if(i == '1'){
                countOne += 1;
            } 
            else{
                result = (result + countOne*(countOne + 1) / 2) % mod;
                countOne = 0;
            }
        }

        result = (result + countOne*(countOne + 1) / 2) % mod;
        return result;
        
    }
};