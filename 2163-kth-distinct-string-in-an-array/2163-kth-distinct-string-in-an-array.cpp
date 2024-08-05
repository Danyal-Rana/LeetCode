class Solution {
public:
    string kthDistinct(vector<string>& arr, int k)
    {
        unordered_map<string, int> myMap;
        vector<string> distinctOrder;

        for (auto s : arr)
        {
            myMap[s]++;

            if (myMap[s]==1)
            {
                distinctOrder.push_back(s);
            }
        }

        for (auto s : distinctOrder)
        {
            if (myMap[s] == 1)
            {
                if (k==1)
                {
                    return s;
                }
                k--;
            }
        }

        return "";
    }
};