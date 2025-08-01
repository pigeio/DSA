class Solution {
public:
    vector<string>result;

    bool isValid(string str){
        int count = 0;
        for(auto &ch : str){
            if(ch == '(') count++;
            else count--;
            if(count < 0) return false;
        }
        return count == 0;
    }
    void generate(string &curr , int n){
        if(curr.length() == 2*n){
            if(isValid(curr)){
                result.push_back({curr});
            }
            return;
        }

        curr.push_back('(');
        generate(curr, n);
        curr.pop_back();

        curr.push_back(')');
        generate(curr, n);
        curr.pop_back();
       
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        generate(curr , n);
        return result;
    }
};