class Solution {
public:
    void DFS(vector<vector<int>>& stones , int index , vector<bool>& visited , int n){
        visited[index] = true;

        for(int i=0;i<n;i++){
            int r = stones[index][0];
            int c = stones[index][1];
            if((visited[i] == false) && (stones[i][0] == r || stones[i][1] == c)){
                DFS(stones, i , visited , n);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<bool>visited (n , false);
        int group = 0;
        for(int i=0;i<n;i++){
            if(visited[i] == true)
            continue;

            DFS(stones,i,visited,n);
            group++;
            
        }
        return (n-group);
    }
};