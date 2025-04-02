class Solution {
public:
    bool isBipartiteBFS(vector<vector<int>>& graph , int node , vector<int> &color , int currcolor){
        queue<int>que;
        que.push(node);
        color[node] = currcolor;

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v : graph[u]){
                if(color[v] == color[u]){
                    return false;
                }else if(color[v] == -1){
                    color[v] = 1-color[u];
                    que.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int>color(v,-1);
        for(int i = 0;i<v;i++){
            if(color[i] == -1){
                if(isBipartiteBFS(graph , i , color , 1) == false){
                   return false;
                }
            }
        }
        return true;
    }
};