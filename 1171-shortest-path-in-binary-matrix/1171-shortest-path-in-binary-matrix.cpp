class Solution {
public:
    typedef pair<int, pair<int,int>> p;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] != 0 || grid[m-1][n-1] != 0) {
            return -1;
        }

        vector<vector<int>>directions = { //directions where a node can travel to find shortest path
            {-1, -1 },{-1, 0},{-1 , 1},
            {0 , -1 },        {0 , 1},
            {1 , -1 },{1 , 0},{1 , 1}
        };

        auto isSafe = [&](int x, int y) { 
        return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0); 
        };


        vector<vector<int>>result(m, vector<int>(n,INT_MAX));

        priority_queue<p , vector<p>, greater<p>> pq;
        
        result[0][0] = 0;
        pq.push({0 ,{0,0}});

        while(!pq.empty()){
            int d = pq.top().first;
            pair<int,int>node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();

            for(auto dir : directions){
                int x_ = x + dir[0]; // new x-coordinates
                int y_ = y + dir[1]; //new y-coordinates
                int dist = 1;

                if(isSafe(x_,y_) && grid[x_][y_] == 0 && d+dist < result[x_][y_]){
                    pq.push({d+dist, {x_, y_}});
                    result[x_][y_] = d+dist;
                }
            }

        }

        if(result[m-1][n-1] == INT_MAX){
            return -1;
        }

        return result[m-1][n-1]+1;
    }
};
