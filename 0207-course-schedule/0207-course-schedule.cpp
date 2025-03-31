class Solution {
public:
    bool isCycleDFS(vector<vector<int>>& adj,int u,vector<bool>&visited,vector<bool> &inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

        for(int &V : adj[u]){
            if(!visited[V] && isCycleDFS(adj , V , visited , inRecursion)){
                return true;
            }else if(inRecursion[V] == true){
                return true;
            }
        }

        inRecursion[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = numCourses;

        for(auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<bool>visited(n , false);
        vector<bool>inRecursion(n , false);

        for(int i = 0;i<n ; i++){
            if(!visited[i] && isCycleDFS(adj , i , visited , inRecursion)){
                return false;
            }
        }return true;
    }
};