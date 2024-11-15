class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int>& arr)
    {
        int n = arr.size();

        // finding jth pointer from rhs
        int j = n - 1;
        while (j > 0 && arr[j] >= arr[j - 1]) // Ensure j - 1 is valid
        {
            j--;
        }

        if (j == 0)
        {
            return 0;
        }

        int i = 0;
        int result = j;

        // finding correct i and j, && finding deleted elements via j - i - 1
        while (i < j && (i == 0 || arr[i] >= arr[i - 1]))
        {
            while (j < n && arr[i] > arr[j])
            {
                j++;
            }

            result = min(result, j - i - 1);
            i++;
        }

        return result;
    }
};