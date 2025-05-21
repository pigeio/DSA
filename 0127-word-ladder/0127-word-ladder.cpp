class Solution {
public:
    typedef pair<string,int>p;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<p>que;
        que.push({beginWord , 1});

        unordered_set<string>st(wordList.begin() , wordList.end());
        st.erase(beginWord);

        while(!que.empty()){
            string currWord = que.front().first;
            int level = que.front().second;
            que.pop();

            if(currWord == endWord) return level;

            for(int i = 0;i<currWord.size();i++){
                int Original = currWord[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    currWord[i] = ch;
                    if(st.find(currWord) != st.end()){
                        st.erase(currWord);
                        que.push({currWord , level+1});
                    }
                }
                currWord[i] = Original;
            }


        }
        return 0;
    }
};