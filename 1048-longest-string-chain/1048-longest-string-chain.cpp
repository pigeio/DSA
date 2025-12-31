class Solution {
public:
    int n;
    int dp[1002][1002];

    bool isPred(string& prev , string& curr){
        int M = prev.size() , N = curr.size();
        if(N-M != 1 || M > N)return false;

        int i = 0 , j = 0;
        while(i < N && j < M){
            if(prev[j] == curr[i]){
                j++;
            }
            i++;
        }
        return j == M;
    }

    static bool comparator(const string&a , const string&b){
        return a.length() < b.length();
    }

    int solve(vector<string>& words, int prev , int curr){
        if(curr == n) return 0;

        if(dp[prev+1][curr] != -1){
            return dp[prev+1][curr];
        }

        int taken = 0 ,notTaken = 0;
        if(prev == -1 || isPred(words[prev] , words[curr])){
            taken = 1 + solve(words,  curr , curr + 1);
        }

        notTaken = solve(words , prev , curr + 1);

        return dp[prev+1][curr] = max(taken , notTaken);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(dp, -1, sizeof(dp));;
        sort(words.begin() , words.end() , comparator);
        return solve(words , -1 , 0);
    }
};