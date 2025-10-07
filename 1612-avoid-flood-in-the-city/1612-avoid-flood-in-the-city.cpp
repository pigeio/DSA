class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int , int>mp;
        set<int>st;
        vector<int>ans(n , 1);

        for(int i = 0; i< n ;i++){
            if(rains[i] == 0){
                st.insert(i);
            }else{
                ans[i] = -1;
            
            if(mp.count(rains[i])){
                auto it = st.lower_bound(mp[rains[i]]);
                if(it == st.end()){
                    return {};
                }

                int day = *it;
                ans[day] = rains[i];
                st.erase(it);
            }
            mp[rains[i]] = i;
            }
        }
        return ans;
    }
};  