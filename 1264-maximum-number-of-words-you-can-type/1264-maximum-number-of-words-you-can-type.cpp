class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool mp[26];
        
        for(auto i : brokenLetters){
            mp[i-'a'] = true;
        }
        int result = 0;
        bool canType = true;
      
        for(auto i : text){
            if(i == ' '){
                if(canType){
                    result++;
                }
                canType = true;
            }else if(mp[i-'a'] == true){
                canType = false;
            }
        }

        if(canType){
            result++;
        }

        return result;
    }
};