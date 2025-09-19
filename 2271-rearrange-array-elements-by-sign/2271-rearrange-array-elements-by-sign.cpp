class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>q1;
        vector<int>q2;
        for(auto i: nums){
            if(i < 0){
                q1.push_back(i);
            }
        }

        for(auto j: nums){
            if(j > 0){
                q2.push_back(j);
            }
        }

        vector<int>ans;
        int i = 0 , j = 0;
        int n1 = q1.size() , n2 = q2.size();

        while(i < q2.size() && j < q1.size()){
            ans.push_back(q2[i++]);
            ans.push_back(q1[j++]);
        }
        

        return ans;
    }
};