class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = numBottles;

        while (numBottles >= numExchange)
        {
            int exchangable = numBottles/numExchange;
            ans += exchangable;
            int curEmptyBottles = numBottles%numExchange;
            numBottles = exchangable + curEmptyBottles;
        }

        return ans;
    }
};