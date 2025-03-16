class Solution {
public:
    bool canEatAll(vector<int>& piles, int mid ,int h){
        int actualHrs = 0;

        for(int &x : piles){
            actualHrs += x/mid;

            if(x % mid != 0){
                actualHrs++;
            } 
        }return actualHrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1 , end = *max_element(piles.begin() , piles.end());
        while(start < end){
            int mid = start + (end-start)/2; //per hrs koko can eat banana
            if(canEatAll(piles , mid , h)){
                end = mid;
            }else{
                start = mid+1;
            } 
        }return end;
    }
};