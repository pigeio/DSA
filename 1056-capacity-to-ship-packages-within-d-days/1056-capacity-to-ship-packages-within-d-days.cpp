class Solution {
public:
    int fun(vector<int>& weights, int mid){
        int days = 1 , load = 0;
        for(int i = 0 ; i<weights.size() ; i++){
            if(load + weights[i] <= mid){
                load += weights[i];
            }else{
                days += 1;
                load = weights[i];
            }
        }return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int start = *max_element(weights.begin() , weights.end());
        int end = accumulate(weights.begin() , weights.end() , 0);
        while(start <= end){
            int mid = start + (end-start)/2;
            int NoOfDays = fun( weights, mid);
            if(NoOfDays <= days){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }return start; // if nothing matches return the minimum value that is start
    }
};