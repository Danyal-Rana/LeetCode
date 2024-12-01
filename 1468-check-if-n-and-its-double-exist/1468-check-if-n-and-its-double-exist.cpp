class Solution {
public:
    int binarySearch(int num, vector<int> &arr)
    {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (arr[mid] == num)
            {
                return mid;
            }
            else if (arr[mid] < num)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }

    bool checkIfExist(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            int j = binarySearch(arr[i] * 2, arr);
            
            if (j!=-1 && j!=i)
                return true;
        }
        return false;
    }
};