class Solution {
public:
    int n ,m;
    int t[501][501];
    int solve(string &word1 ,string &word2,  int i , int j){
        if(j == m)return n-i;
        if(i == n)return m-j;

        if(t[i][j] != -1){
            return t[i][j];
        }

        if(word1[i] == word2[j]){
            return t[i][j] = solve(word1 , word2 , i+1 , j+1);
        }

        int del = 1 + solve(word1 , word2 , i+1 , j);
        int insert = 1 + solve(word1 , word2 , i , j+1);
        int replace = 1 + solve(word1 , word2 , i+1 , j+1);

        return t[i][j] = min({del , insert,  replace});
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        memset(t , -1 , sizeof(t));
        return solve(word1 , word2 , 0 , 0);
    }
};