class Solution {
public:
    string orderlyQueue(string s, int k) {
       if(k>1){
        sort(s.begin(),s.end());
       }
       
       string result = s;
       //for (k == 1)
       int n = s.length();
       for(int l=1;l<n;l++){
        string temp = s.substr(l) + s.substr(0 , l);
        result = min(result , temp);

       }
        return result;
    }
    
};