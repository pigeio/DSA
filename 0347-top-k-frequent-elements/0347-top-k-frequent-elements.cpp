class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        for(auto & i : nums){
            mp[i]++;
        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;
        for(auto & it: mp){
           int val = it.first;
           int freq = it.second;

           pq.push({freq, val});
           if(pq.size() > k){
            pq.pop();
           }
        }

        vector<int>result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};