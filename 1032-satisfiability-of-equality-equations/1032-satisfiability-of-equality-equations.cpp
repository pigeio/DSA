class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){ //path compressed code
       if(x == parent[x])
       return x;

       return parent[x] = find(parent[x]);
    }

    //rank optimized code
    void unionSet(int x , int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent){
            return;
        }

        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent; 
        }else{
            parent[x_parent] = y_parent;

            rank[y_parent] += 1;
        }

    }
    

    bool equationsPossible(vector<string>& equations) {
        
        parent.resize(26);  //since there are 26 letters
        rank.resize(26 , 0);

        for(int i = 0; i<26;i++){
            parent[i] = i; //start me sab khud ke parent hote hai
            
        }

        for(string &s : equations){ // agar '=' wala case hoga toh union kr denge 
            if(s[1] == '='){ //a == b
                unionSet(s[0]-'a' , s[3]-'a');
            }
        }

        for(string &s : equations){  // agar '!' wala case hoga toh validity check karenge
            if(s[1] == '!'){ 
                char first = s[0];  //a
                char second = s[3];  //b

                int first_parent = find(first - 'a');
                int second_parent = find(second - 'a');

                if( first_parent ==  second_parent)
                return false;
            }
        }
        return true;
    }
};