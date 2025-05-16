class Solution {
public:
    void bfs( unordered_map<int,vector<int>> &adj , int i , vector<bool> &visited , int  &v , int &e){
        queue<int>que;
        que.push(i);
        visited[i] = true;

        while(!que.empty()){
            int curr = que.front();
            que.pop();
            v++;
            e += adj[curr].size();

            for(int &neighbor : adj[curr]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    que.push(neighbor);
                }
            }
        }

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>>adj;
        int result = 0;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n , false);

        for(int i = 0 ; i<n ; i++){
            if(visited[i] == true){ //ho sakta hai jab hum dusre diagram ko dekhenge toh pehle wala        element visited ho
                continue;
            }
            int v = 0;
            int e = 0;
            bfs(adj , i , visited , v , e);

            if(v*(v-1) /2 == e/2){
                result++;
            }
        }
        return result;
    }
};