class Solution {
public:
    void rotate(string& s , int b){
        reverse(s.begin() , s.end());
        reverse(s.begin() , s.begin()+b);
        reverse(s.begin()+b , s.end());
    }
    string findLexSmallestString(string s, int a, int b) {
        string smallestString =  s;
        unordered_set<string>visited;
        queue<string>q;
        q.push(s);
        visited.insert(s);

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(curr < smallestString){
                smallestString = curr;
            }

            //1st operation(add a)
            string temp = curr;
            for(int i = 1; i< temp.length(); i += 2){
                temp[i] = ((temp[i]-'0'+ a) % 10) + '0';
            }

            if(!visited.count(temp)){
                visited.insert(temp);
                q.push(temp);
            }

            //2nd operation(rotate)
            rotate(curr , b);

            if(!visited.count(curr)){
                visited.insert(curr);
                q.push(curr);
            }
        }
        return smallestString;
    }
};