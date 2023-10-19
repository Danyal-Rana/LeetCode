class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        vector<int> myVector;
        sort (arr.begin(), arr.end());

        for (int i=0; i<arr.size(); )
        {
            int myCounter = 0;
            for (int j=i; j<arr.size(); j++)
            {
                if (arr[i] == arr[j])
                {
                    myCounter++;
                }
                else
                {
                    break;
                }
            }
            myVector.push_back (myCounter);
            i = i+myCounter;
        }

        sort (myVector.begin(), myVector.end());

        for (int i=0; i<myVector.size()-1; i++)
        {
            if (myVector[i] == myVector[i+1])
            {
                return false;
            }
        }
        return true;
    }
};