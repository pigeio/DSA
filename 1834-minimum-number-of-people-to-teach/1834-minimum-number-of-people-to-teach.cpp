class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>saduser;

        for(auto& friends : friendships){
            int u = friends[0] - 1;
            int v = friends[1] - 1;

            unordered_set<int>langSet(begin(languages[u]) , end(languages[u]));
            bool canTalk = false;
            for(int lang : languages[v]){
                if(langSet.count(lang)){
                    canTalk = true;
                    break;
                }
            }

            if(!canTalk){
                saduser.insert(u);
                saduser.insert(v);
            }
        }

        vector<int>langTable(n+1 , 0);
        int mostKnownLang = 0;
        for(int user : saduser){
            for(int lang : languages[user]){
                langTable[lang]++;
                mostKnownLang = max(mostKnownLang , langTable[lang]);
            }
        }

        return saduser.size() - mostKnownLang;
    }
};