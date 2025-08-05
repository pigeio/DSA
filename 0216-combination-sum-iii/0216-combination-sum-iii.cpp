class Solution {
public:
    vector<vector<int>>result;
    void find(int idx ,int k , int n, vector<int>set){
        if(set.size() == k && n == 0){
            result.push_back(set);
            return;
        }
        if(set.size() > k || n < 0) return;

        for(int i = idx; i <= 9 ; i++){
            if(i > idx && i == i-1){
                continue;
            }
            set.push_back(i);
            find(i+1, k , n-i ,set);
            set.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>set;
        find(1 , k , n, set);
        return result;
    }
};