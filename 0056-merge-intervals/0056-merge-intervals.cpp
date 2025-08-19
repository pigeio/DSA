class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(intervals.empty()) return{};

        sort(intervals.begin() , intervals.end());

        vector<vector<int>>mergedInter;
        mergedInter.push_back(intervals[0]);

        for(int i = 1; i< n; i++){
            vector<int>& current_inter = intervals[i];
            vector<int>& lastmerged_inter = mergedInter.back();

            if(current_inter[0] <= lastmerged_inter[1]){
                lastmerged_inter[1] = max(current_inter[1] , lastmerged_inter[1]);

            }else{
                mergedInter.push_back(current_inter);
            }
        }
        return mergedInter;
    }
};