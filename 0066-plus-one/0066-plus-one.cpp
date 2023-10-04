class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int toAdd = 1;

        vector <int> myVector;

        for (int i=digits.size()-1; i>=0; i--)
        {
            int temp = digits[i] + toAdd;

            digits[i] = temp%10;

            toAdd = temp/10;
        }

        if (toAdd > 0)
        {
            myVector.push_back (toAdd);
        }

        for (int i=0; i<digits.size(); i++)
        {
            myVector.push_back (digits[i]);
        }

        return myVector;
    }
};