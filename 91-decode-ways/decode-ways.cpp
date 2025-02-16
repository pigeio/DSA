class Solution {
public:
    int t[101];
    int solve(string& s, int& n, int i){
        if(t[i] != -1){
            return t[i];
        }

        if(i == n)
        return t[i] = 1;

        if(s[i] == '0'){
            return t[i] = 0;
        }

        int result = solve(s,n,i+1);

        if(i+1 < n){
             if(s[i]== '1' || (s[i]== '2' && s[i+1]<= '6')){
             result += solve(s,n,i+2);
            }
        }

        return t[i] =  result;

        
    }
    int numDecodings(string s) {
        int n = s.length();

        memset(t,-1,sizeof(t));

        return solve(s,n,0);
    }   
};