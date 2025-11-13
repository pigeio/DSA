class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int countOne = 0;
        int op = 0;
        int i = 0;
        while(i < n){
            if(s[i] == '0'){
                op += countOne;
                while(i < n && s[i] == '0')
                i++;
            }else{
                countOne++;
                i++;
            }
            
        }

        return op;
    }
};