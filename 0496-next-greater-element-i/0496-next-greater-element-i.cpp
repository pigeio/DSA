class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans;
        unordered_map<int,int>mp;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=m-1; i>=0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]] = -1;
            }else{
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for(int i=0; i<n; i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};