class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for(int i =0;i<n;i++){
            //base case
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
                //overlapping
                vector<int>& v  = ans.back();
                int y = v[1];
                if(intervals[i][0] <= y){
                    v[1] = max(y,intervals[i][1]);
                }

                //not overlapping 
                else{
                    ans.push_back(intervals[i]);
                }
            }
        } return ans;

    } 
};