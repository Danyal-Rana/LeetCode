class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations)
    {
        int myNum = 0;

        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "++X" || operations[i] == "X++")
            {
                myNum++;
            }
            else if (operations[i] == "--X" || operations[i] == "X--")
            {
                myNum--;
            }
        }

        return myNum;
    }
};