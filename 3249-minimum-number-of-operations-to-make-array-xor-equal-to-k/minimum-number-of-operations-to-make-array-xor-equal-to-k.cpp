class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int temp = 0;
        for(auto i : nums)
            temp ^= i;

        temp = (temp ^ k);
        
        int counter = 0;
        while(temp){
            counter++;
            temp = (temp&(temp -1));
        }

        return counter;
    }
};