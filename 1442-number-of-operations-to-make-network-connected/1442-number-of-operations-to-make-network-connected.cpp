class Solution {
public:

    vector<int>parent;
    vector<int>rank;

    //path compressed code
    int find(int x){
        if(x == parent[x]){ //starting me sab apna he parent hoga
            return x;
        }
        return parent[x] = find(parent[x]);
        
    }

    void unionSet(int x , int y){  //rank optimized code
        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }else{
            parent[x_parent] = y_parent;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        
        parent.resize(n);
        rank.resize(n, 0);

        int componenet = n;

        for(int i=0;i<n;i++){ // starting me sab apna he parent hoga
            parent[i] = i;
        }

        for(auto &vec : connections){
            if(find(vec[0]) != find(vec[1])){ //agar parent nhi milega toh usko merge hone ke liye bolenge 
                unionSet(vec[0] , vec[1]); //yaha pe merge kr diye i.e a<--b
                componenet--;
            }
        }
        return componenet-1;
    }
};