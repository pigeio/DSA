class Solution {
public:
    int n , m;
    int t[2001][2001];
    bool solve(string &s, string &p , int i, int j){
        if(i == n && j == m)return true;

        if(t[i][j] != -1){
            return t[i][j];
        }

        bool ans = false;

        if(i < n && s[i] == p[j] || p[j] == '?'){
            ans = solve(s , p , i+1 , j+1);
        }

        if(p[j] =='*'){
            bool option1 = solve(s , p , i ,j+1);
            bool option2 = (i < n && solve(s , p ,i+1 , j));
            ans =  option1 || option2;
        }
        return t[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        n = s.length();
        m = p.length();
        memset(t , -1 , sizeof(t));

        return solve(s , p , 0 , 0);

    }
};