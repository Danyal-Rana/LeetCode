class Solution {
public:
    vector<int> replaceElements(vector<int>& arr)
    {
        if (arr.size() == 1)
        {
            arr[0] = -1;
            return arr;
        }

        int gNum = -1;

        for (int i=arr.size()-1; i>=0; i--)
        {
            int temp = arr[i];

            arr[i] = gNum;

            if (gNum < temp)
            {
                gNum = temp;
            }
        }

        return arr;
    }
};