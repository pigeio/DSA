class Solution {
public:
    vector<int>getNSL(vector<int>&height){
       stack<int>st;
       int n = height.size();
       vector<int>result(n);

       for(int i=0;i<n;i++){
        while(!st.empty() && height[st.top()] >= height[i]){
            st.pop();
        }
        result[i] = st.empty() ? -1 : st.top();
        st.push(i);
       }
       return result;
    }

    vector<int>getNSR(vector<int>&height){
       stack<int>st;
       int n = height.size();
       vector<int>result(n);

       for(int i=n-1 ;i>=0 ;i--){
        while(!st.empty() && height[st.top()] >= height[i]){
            st.pop();
        }
        result[i] = st.empty() ? n : st.top();
        st.push(i);
       }
       return result;
    }


    int findMaxArea(vector<int>&height){
        vector<int>NSL = getNSL(height);
        vector<int>NSR = getNSR(height);
        int Area = 0;
        int n = height.size();

        for(int i =0; i<n; i++){
           int width = NSR[i] - NSL[i] - 1;
           int currArea = (height[i] * width);

           Area = max(Area , currArea);
        }
        return Area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>height(m); // here we start converting 2D matrix to 1D by taking name height

        for(int i=0;i<m;i++){
            height[i] = matrix[0][i] == '1' ? 1 : 0;
        }
        int maxArea = findMaxArea(height);

        for(int r=1 ; r < n; r++){
            for(int c = 0; c<m ;c++){
                if(matrix[r][c] == '0'){
                    height[c] = 0;
                }else{
                    height[c] += 1;
                }
            }
            maxArea = max(maxArea , findMaxArea(height));
        }
        return maxArea; 
    }
};