class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if(m != n){
            return false;
        }

        vector<int>freq1(26);
        vector<int>freq2(26);

        for(int i=0;i<n;i++){
            char ch1 = word1[i];
            char ch2 = word2[i];

            int idx1 = ch1-'a';
            int idx2 = ch2-'a';

            freq1[idx1]++;
            freq2[idx2]++;
        }
        //agar koi char w1 me nhi hai toh w2 me v nhi hona chaiye && agar hai toh dono me ho.
        for(int i=0; i<26 ; i++){
            if(freq1[i] != 0 && freq2[i] != 0) continue;

            if(freq1[i] == 0 && freq2[i] == 0) continue;

            return false;
        }
        // check whether the freq is equal or not 
        sort(freq1.begin() , freq1.end() );
        sort(freq2.begin() , freq2.end() );

        return freq1 == freq2 ; 
    }   
};