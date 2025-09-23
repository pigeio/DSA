class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int , int>mp;
        for(auto i : nums){
            mp[i]++;
        }

        int maxFreq = 0;
        for(auto& i : mp){
            maxFreq = max(maxFreq , i.second);
        }

        int count = 0;
        for(auto& i :mp){
            if(maxFreq == i.second){
                count += i.second;
            }
        }
        return count;

    
    }
};