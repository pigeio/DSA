class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<>>pq;

        for(int i=0; i<n ; i++){
            pq.push({arr[i] , i});
        }

        int rank = 1;
        int pre_val = INT_MAX;
        vector<int>result(n);

        while(!pq.empty()){
            auto[val , idx] = pq.top();
            pq.pop();

            if(val != pre_val){
                pre_val = val;
                result[idx] = rank++;
            }else{
                result[idx] = rank - 1;
            }
        }
        return result;
    }
};