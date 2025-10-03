class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;
        int drunk = numBottles;

        while(empty >= numExchange){
            empty -= numExchange;
            drunk++;
            empty++;
            numExchange++;
        }

        return drunk;
    }
};