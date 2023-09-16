class Solution {
public:
    vector<int> replaceElements(vector<int>& arr)
    {
        

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