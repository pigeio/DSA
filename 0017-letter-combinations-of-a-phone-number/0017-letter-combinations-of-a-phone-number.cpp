class Solution {
public:
    void find(int idx, string digits, string storageH, unordered_map<char, string>& mp, vector<string> &results){
        if(idx == digits.length()){
            results.push_back(storageH);
            return;
        }

        char ch = digits[idx];
        string str = mp[ch];

        for(auto & c : str){
            storageH.push_back(c);
            find(idx+1,  digits, storageH, mp, results);
            storageH.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<string>results;

        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string storageH = "";
        find(0 , digits ,storageH,mp,results);
        return results;
    }
};