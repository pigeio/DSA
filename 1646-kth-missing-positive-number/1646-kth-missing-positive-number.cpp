class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 0 , end = n-1;
        while(start <=end){
            int mid = start + (end -start)/2;
            int NoOfMissingElement  = arr[mid] - (mid+1);
            if(NoOfMissingElement < k){
                start = mid +1;
            }else{
                end = mid-1;
            }
        }return k + end + 1;
    }
};