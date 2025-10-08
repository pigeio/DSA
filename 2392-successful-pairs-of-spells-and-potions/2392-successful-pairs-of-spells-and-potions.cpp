class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin() , potions.end());
        int maxPotions = potions[m-1];
        vector<int>ans;

        for(int i = 0; i< n ;i++){
            int spell = spells[i];

            long long minPotions = ceil((1.0*success)/spell);
            if(minPotions > maxPotions){
                ans.push_back(0);
                continue;
            }
            int index = lower_bound(potions.begin(),  potions.end() , minPotions) - potions.begin();

            int more = m - index;
            ans.push_back(more);
        }

        return ans;
    }
};