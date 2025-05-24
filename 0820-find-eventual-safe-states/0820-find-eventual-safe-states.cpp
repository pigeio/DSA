class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> rev(V);
        vector<int>Indegree(V , 0);
        queue<int>que;

        for(int u = 0; u<V; u++){
            for(auto &v : graph[u]){
                rev[v].push_back(u);
                Indegree[u]++;
            }
        }

        for(int i = 0; i<V;i++){
            if(Indegree[i] == 0){
                que.push(i);
            }
        }

        vector<bool>safeNode(V ,false);
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            safeNode[curr] = true;

            for(auto &v : rev[curr]){
                Indegree[v]--;

                if(Indegree[v] == 0){
                    que.push(v);
                }
            }
        }

        vector<int>countSafeNode;

        for(int i=0;i<V;i++){
            if(safeNode[i] == true){
                countSafeNode.push_back(i);
            }
        }

        return countSafeNode;
    }
};