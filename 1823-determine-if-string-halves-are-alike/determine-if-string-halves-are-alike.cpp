class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int n = s.length();

        unordered_set<char>vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int mid = n/2;
        int i = 0 , j = mid;

        int countleft = 0;
        int countright = 0;

        for(int i=0 ;i<mid ;i++){
            if(vowels.find(s[i]) != vowels.end()){
            countleft++;
            }
        }
        for(int j=mid ;j<n ;j++){
            if(vowels.find(s[j]) != vowels.end()){
            countright++;
           }
        }  
        return countleft == countright;
        
    }
};