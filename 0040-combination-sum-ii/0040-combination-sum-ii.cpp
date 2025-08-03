class Solution {
public:
    vector<vector<int>>result;
    void find(vector<int>& candidates, int target, int idx ,vector<int>storageHouse){
        if(target < 0) return ;
        if(target == 0){
            result.push_back(storageHouse);
            return;
        }

        for(int i = idx ;i < candidates.size();i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }
            storageHouse.push_back(candidates[i]);
            find(candidates , target- candidates[i] , i+1, storageHouse);
            storageHouse.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<int>storageHouse;
        find(candidates , target , 0, storageHouse);
        return result;
    }
};