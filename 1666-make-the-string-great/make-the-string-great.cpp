class Solution {
public:
    string makeGood(string s) {
        if(s.length() <= 1){
            return s;
        }

        string result = "";
        int n = s.length();
        for(int i=0;i<n;i++){
            if(!result.empty() && abs(result.back()- s[i]) == 32){
                result.pop_back();
            }else{
                result.push_back(s[i]);
            }

        }
        return result;
    }

};