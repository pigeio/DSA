class Solution {
public:
    typedef pair<int,int> p;
    vector<vector<int>>directions {{-1,0} , {1,0} ,{0,-1} , {0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int oldColor = image[sr][sc];
        if(oldColor == color) return image;

        queue<p>que;
        que.push({sr,sc});
        image[sr][sc] = color;

        while(!que.empty()){
            p curr = que.front();
            que.pop();

            int r = curr.first;
            int c = curr.second;

            for(auto &dir : directions){
                int new_r = r + dir[0];
                int new_c = c + dir[1];

                if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m  && image[new_r][new_c] == oldColor){
                    image[new_r][new_c] = color;
                    que.push({new_r , new_c});
                }
            } 
        }
        return image;
    }
};