class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();

        if(n != m){
            return false;
        }

        for(int count = 0; count <=n ;count++){
            rotate(s.begin() ,s.begin()+1 , s.end());
            if( s == goal){
                return true;
            }
        }return false;
    }
};