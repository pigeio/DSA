class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256 , -1);
        int n = s.length();
        int maxLength = 0;
        int l = 0 , r = 0;
        while(r < n){
            if(s[r] != -1){
                if(mp[s[r]] >= l){
                    l = mp[s[r]] + 1;
                }
            }
            int length = r-l+1;
            maxLength = max(maxLength , length);
            mp[s[r]] = r;
            r++;
        }
        return maxLength;
    }
};