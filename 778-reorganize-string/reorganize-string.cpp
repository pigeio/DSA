class Solution {
public:
    typedef pair<int , char> P;
    string reorganizeString(string s) {
        int n = s.length();

        vector<int> count(26,0); //

        for(char &ch : s){ //here we find the frequency of each char
            count[ch-'a']++;

            if(count[ch-'a'] > (n+1)/2){  // if count of char is greater than (n+1)/2 then return empty string
                return "";
            }
        }

        priority_queue<P , vector<P>>pq; //max_heap

        for(char ch='a'; ch<='z'; ch++){  //now we iterate on our string
            if(count[ch-'a'] > 0){  //if count is more than 0 we push freq and that ch
                pq.push({count[ch-'a'] , ch}); 
            }

        } string result =  "";

        while(pq.size() >= 2){
            auto P1 = pq.top();
            pq.pop();

            auto P2 = pq.top();
            pq.pop();

            result.push_back(P1.second);P1.first--;
            result.push_back(P2.second);P2.first--;

            if(P1.first > 0){
                pq.push(P1);
            }
            if(P2.first > 0){
                pq.push(P2);
            }
        }

        if(!pq.empty()){
            result.push_back(pq.top().second);
        }
        return result;
    }
};