class Solution {
public:
    vector<vector<int>>result;

    void rocket(int i ,vector<int>& candidates , int tar, int s ,vector<int>&ds ,int N){
        if(i >= N){
            if(s == tar){
                result.push_back(ds);
            }
            return;
        }
        
        if(s+candidates[i] <= tar){
        ds.push_back(candidates[i]);
        s += candidates[i];
        rocket(i ,candidates ,tar ,s, ds,  N);
        s -= candidates[i];
        ds.pop_back();
        }
        rocket(i+1 ,candidates , tar,s , ds ,N);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int N = candidates.size();
        vector<int>ds;
        rocket(0, candidates, target ,0 ,ds ,N);
        return result;
    }
};