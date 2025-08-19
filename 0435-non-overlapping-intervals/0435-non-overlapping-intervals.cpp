class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end(),[](auto &a , auto &b){
            return a[1] < b[1];
        });
        int i = 0 , j = 1;
        int count = 0;

        while(j < n){
            vector<int>current_I = intervals[i];
            vector<int>next_I = intervals[j];

            int cs = current_I[0];
            int ce = current_I[1];

            int ns = next_I[0];
            int ne = next_I[1];

            //non-overlapping
            if(ce <= ns){
                i = j;
                j++;
            }else if(ce <= ne){ //overlapping
                j++;
                count++;
            }else if(ce > ne){ //overlapping
                i = j;
                j++;
            }
        }
        return count;
    }
};