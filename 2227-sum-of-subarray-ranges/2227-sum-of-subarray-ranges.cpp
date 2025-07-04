class Solution {
public:
    // Next Smaller Right
    vector<int> getNSR(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> result(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    // Next Smaller Left
    vector<int> getNSL(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    // Next Greater Right
    vector<int> getNGR(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> result(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return result;
    }

    // Next Greater Left
    vector<int> getNGL(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            result[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return result;
    }

    // Sum of all subarrays where arr[i] is maximum
    long long sumOfMax(vector<int>& arr) {
        int n = arr.size();
        vector<int> NGL = getNGL(arr, n);
        vector<int> NGR = getNGR(arr, n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NGL[i];
            long long right = NGR[i] - i;
            sum += (long long)arr[i] * left * right;
        }
        return sum;
    }

    // Sum of all subarrays where arr[i] is minimum
    long long sumOfMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NSL[i];
            long long right = NSR[i] - i;
            sum += (long long)arr[i] * left * right;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumOfMax(nums) - sumOfMin(nums);
    }
};
