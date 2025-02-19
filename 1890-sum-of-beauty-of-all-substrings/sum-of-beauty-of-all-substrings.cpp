class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int result = 0 ;
        
        for(int i =0; i<n;i++){
            unordered_map<char,int>mp;
            int maxfreq = 0;
            for(int j=i; j<n;j++){
                mp[s[j]]++;
                maxfreq = max(maxfreq , mp[s[j]]);
                int minfreq = INT_MAX;
                for(auto &it :mp){
                   minfreq = min(minfreq , it.second);
                }
                result += (maxfreq  - minfreq);
            }
        }return result;
    }
};