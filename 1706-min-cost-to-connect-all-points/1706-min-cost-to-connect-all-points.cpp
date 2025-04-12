class Solution {
public:
    typedef pair<int,int> p;

    int primsAlgo(vector<vector<p>> &adj , int V){
       priority_queue<p , vector<p> , greater<p>> pq;
        
        vector<int>visited(V, false);

        pq.push({0,0});
        int sum = 0;

        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(visited[node] == true)
            continue;

            visited[node] = true;
            sum += wt;

            for(auto &neighbor : adj[node]){
                int adjNode = neighbor.first;
                int node_wt = neighbor.second;

                if(!visited[adjNode]){
                    pq.push({node_wt , adjNode});
                }
            }
        }
        return sum;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<p>> adj(V);

        for(int i = 0; i<V ; i++){
            for(int j =i+1 ; j< V; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({j , dist});
                adj[j].push_back({i , dist});
            }
        }

        return primsAlgo(adj , V);
    }
};