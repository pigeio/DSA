class Solution {
public:
    void dfs(vector<vector<int>>& stones , int index ,  vector<bool>&visited){
        visited[index] = true;
        int n  = stones.size();

        for(int i = 0 ; i< n; i++){
            if((visited[i] == false) && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]))
            dfs(stones , i , visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>visited( n , false);
        int group = 0;

        for(int i = 0; i< n ;i++){
            if(visited[i] == true) continue;

            if(visited[i] == false){
                dfs(stones , i , visited );
                group += 1;
            }
        }
        return n-group;
    }
};