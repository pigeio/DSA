class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{-1,0},{0,1},{1,0},{0,-1},{-1,1},{1,1},{1,-1},{-1,-1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Check if start or end is blocked
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) {
            return -1;
        }
        
        // Special case: single cell
        if(n == 1 && m == 1) {
            return 1;
        }
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        
        pq.push({1, {0, 0}});  // Start with distance 1 (count the starting cell)
        result[0][0] = 1;
        
        while(!pq.empty()) {
            int d = pq.top().first;
            pair<int, int> node = pq.top().second;
            pq.pop();
            
            int x = node.first;
            int y = node.second;
            
            // If we reached the destination
            if(x == n-1 && y == m-1) {
                return d;
            }
            
            // Skip if we've already found a better path
            if(d > result[x][y]) continue;
            
            for(auto& dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int newDist = d + 1;
                
                if(isSafe(x_, y_) && grid[x_][y_] == 0 && newDist < result[x_][y_]) {
                    result[x_][y_] = newDist;
                    pq.push({newDist, {x_, y_}});
                }
            }
        }
        
        return -1;  // No path found
    }
};