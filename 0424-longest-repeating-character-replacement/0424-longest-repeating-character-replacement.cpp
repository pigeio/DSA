class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxfreq = 0;
        int maxLength = 0;
        int l = 0 , r = 0;
        vector<int>freq(26 , 0);
        while(r < n){
            freq[s[r]-'A']++;
            maxfreq = max(maxfreq , freq[s[r]-'A']);
            if((r-l+1)- maxfreq > k){
                freq[s[l]-'A']--;
                l++;
            }
            
            maxLength = max(maxLength , r-l+1);
            r++;
            
        }
        return maxLength;
    }
};