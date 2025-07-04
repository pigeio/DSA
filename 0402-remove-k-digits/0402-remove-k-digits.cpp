class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n = num.size();
        for(int i = 0; i< n;i++){
            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k--;
            }
            if(!st.empty() || num[i] != '0'){
                st.push(num[i]);
            }
        }
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

       
        int s = st.size();
        if(s == 0) return "0";
        vector<char>result(s);
        int i = s-1;
        while(!st.empty()){
            result[i] = st.top();
            st.pop();
            i--;
        }
        string finalResult(result.begin() , result.end());

        return finalResult;
    }
};