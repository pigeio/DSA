class Solution {
public:
    typedef pair<long long,int>P;
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int time = it[2];

            adj[u].push_back({v , time});
            adj[v].push_back({u , time});
        }
        priority_queue<P , vector<P> , greater<P>> pq; //min_heap
        vector<long long> result( n , LLONG_MAX);
        vector<int>pathCount(n , 0);

        result[0] = 0;
        pq.push({0 , 0});
        pathCount[0] = 1;

        while(!pq.empty()){
            long long currTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto &it : adj[currNode]){
                int neigh = it.first;
                int time = it.second;

                if(currTime+time < result[neigh]){
                    result[neigh] = currTime+time;
                    pq.push({currTime+time , neigh});
                    pathCount[neigh] = pathCount[currNode];
                }else if(currTime+time == result[neigh]){
                    pathCount[neigh] = (pathCount[neigh]+pathCount[currNode]) % M ;
                }
            }
        }
        return pathCount[n-1];
    }
};