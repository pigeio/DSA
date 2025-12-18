class Solution {
public:
    int n;
    int t[1002][1002];

    bool isPred(string &prev, string &curr) {
        int M = prev.size(), N = curr.size();
        if (N - M != 1) return false;

        int i = 0, j = 0;
        while (j < N) {
            if (i < M && prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i == M;
    }

    static bool myComparator(const string &a, const string &b) {
        return a.length() < b.length();
    }

    int solve(vector<string>& words, int prev, int curr) {
        if (curr == n) return 0;

        if (t[prev + 1][curr] != -1)
            return t[prev + 1][curr];

        int take = 0;
        if (prev == -1 || isPred(words[prev], words[curr])) {
            take = 1 + solve(words, curr, curr + 1);
        }

        int nottake = solve(words, prev, curr + 1);

        return t[prev + 1][curr] = max(take, nottake);
    }

    int longestStrChain(vector<string>& words) {
        n = words.size();
        memset(t, -1, sizeof(t));
        sort(words.begin(), words.end(), myComparator);
        return solve(words, -1, 0);
    }
};
