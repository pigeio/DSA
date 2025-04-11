class Solution {
public:
    typedef pair<int , pair<int,int>> p;
    vector<vector<int>> directions = {{-1,0} , {0,-1} , {0,1} , {1,0}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>result(m , vector<int>(n, INT_MAX));

        priority_queue<p , vector<p> , greater<p>> pq;

        auto isSafe = [&](int x, int y){
            return x >= 0 && x < m && y >= 0 && y < n;      
        };

        result[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff = pq.top().first;

            pair<int,int> node = pq.top().second;
            int x = node.first;
            int y = node.second;

            pq.pop();

            for(auto &dir : directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_, y_)){
                    int absdiff = abs(heights[x_][y_] - heights[x][y]);
                    int maxDiff = max(diff , absdiff);

                    if(result[x_][y_] > maxDiff){
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff ,{x_,y_}});
                    }
                }
            }
        }

        return result[m-1][n-1];

    }
};