class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();

        stack<char>st;
        int currentDepth = 0, maxDepth = 0;
        int i = 0;

        for(auto &ch : s){
            if(ch == '('){
                st.push('(');
                currentDepth = st.size();
                maxDepth = max(currentDepth , maxDepth);
            }else if(ch == ')'){
                st.pop();
            }
        }return maxDepth;
    }
};