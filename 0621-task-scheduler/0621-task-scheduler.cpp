class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26, 0);
        int result = 0;

        for(auto &i : tasks){
            mp[i - 'A']++;
        }

        priority_queue<int>pq;
        for(auto &i: mp){
            if(i > 0){
                pq.push(i);
            }
        }
        
        
        while(!pq.empty()){
            vector<int>temp;
            for(int i =1 ; i<= n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(auto &f : temp){
                if(f > 0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                result += temp.size();
            }else{
                result += n+1;
            }
        }
        return result;
    }
};