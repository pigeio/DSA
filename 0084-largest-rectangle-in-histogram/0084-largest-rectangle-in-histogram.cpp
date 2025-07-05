class Solution {
public:
    vector<int>getNSL(vector<int>& heights , int n){
        stack<int>st;
        vector<int> result(n);

        for(int i =0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            result[i] = st.empty()? -1: st.top();
            st.push(i);
        }
        return result;
    }

     vector<int>getNSR(vector<int>& heights , int n){
        stack<int>st;
        vector<int> result(n);

        for(int i =n-1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] > heights[i]){
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>NSL = getNSL(heights, n);
        vector<int>NSR = getNSR(heights, n);
        int Area = 0;

        for(int i =0 ; i<n;i++){
            int width = NSR[i]-NSL[i]-1;
            int currArea =(heights[i] * width);
            Area = max(Area , currArea);

        }
        return Area;
    }
};