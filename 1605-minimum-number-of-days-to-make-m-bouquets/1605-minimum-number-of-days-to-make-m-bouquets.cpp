class Solution {
public:
    int canMakeBouq(vector<int>& bloomDay , int mid , int k ){
        int bouquetCount = 0;
        int countAdjacentFlower = 0;

        for(int i = 0 ; i<bloomDay.size() ; i++){
            if(bloomDay[i] <= mid){
                countAdjacentFlower++;
                if(countAdjacentFlower == k){
                bouquetCount++;
                countAdjacentFlower = 0;
                }
            }else{
                countAdjacentFlower = 0;
            }
        }
        return bouquetCount;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m * k > n) return -1;

        int start = 1 , end = *max_element(bloomDay.begin() , bloomDay.end());
        int minDays = -1;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(canMakeBouq(bloomDay , mid , k) >= m){
                minDays = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }return minDays;
    }
};