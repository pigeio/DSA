class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> result(n, INT_MAX);
        
        unordered_map<int, vector<pair<int, int>>> adj;
        
        // Build adjacency list
        for(auto &it : flights) {
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            
            adj[u].push_back({v, cost});
        }
        
        queue<pair<int, int>> que; // {node, cost}
        
        que.push({src, 0});
        result[src] = 0;
        int steps = 0;
        
        while(!que.empty() && steps <= k) {
            int size = que.size();
            
            // Process all nodes at current level
            for(int i = 0; i < size; i++) {
                int u = que.front().first;
                int d = que.front().second;
                que.pop();
                
                for(auto &it : adj[u]) {
                    int v = it.first;      // destination node
                    int cost = it.second;  // flight cost
                    
                    if(d + cost < result[v]) {
                        result[v] = d + cost;
                        que.push({v, d + cost});
                    }
                }
            }
            steps++;
        }
        
        if(result[dst] == INT_MAX) {
            return -1;
        }
        return result[dst];
    }
};