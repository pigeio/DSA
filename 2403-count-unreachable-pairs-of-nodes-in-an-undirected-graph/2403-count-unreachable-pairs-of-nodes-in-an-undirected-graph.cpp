class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){
        if(x == parent[x])
        return x;

        return parent[x] = find(parent[x]);
    }

    void unionSet(int x , int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        } else{
            parent[x_parent] = y_parent;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        parent.resize(n);
        rank.resize(n , 0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }

        for(auto &vec : edges){ //now start processing edges
            int u = vec[0];
            int v = vec[1];
            unionSet(u,v);
        }

        unordered_map<int , int>mp; // ek map banao jo ke parent or uske size ko contain krta ho
        for(int i=0;i<n;i++){
            int parent = find(i);
            mp[parent]++;
        }

        long long result = 0; //ab hum log ko result chaiye
        long long remainingNodes = n;
        for(auto &it : mp){  //result se pehle humko size chaiye
            long long size = it.second;

            result += size * (remainingNodes - size);
            remainingNodes -= size;
        }
        return result;
    }
};