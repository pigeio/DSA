class Solution {
public:
    typedef pair<char , int>p;
    string frequencySort(string s) {

        unordered_map<char,int>mp;
        for(char ch : s){
            mp[ch]++;
        }

        struct lambda{
            bool operator() (p &p1 , p&p2){
                return p1.second < p2.second ;
            }
        };

        priority_queue<p, vector<p> , lambda>pq;

        for(auto it:mp){
            pq.push({it.first , it.second});
        }

        string result = "";
        while(!pq.empty()){
            p temp = pq.top();
            pq.pop();

            result += string(temp.second , temp.first);
        }
        return result;
    }
};