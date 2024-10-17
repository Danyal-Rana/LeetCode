class Solution {
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        int n = s.size();

        vector<int> maxRight(n);

        maxRight[n-1] = n-1;

        for (int i=n-2; i>=0; i--)
        {
            int rightMaxIdx = maxRight[i+1];
            int rightMaxEle = s[rightMaxIdx];

            maxRight[i] = s[i]>rightMaxEle ? i : rightMaxIdx;
        }

        for (int i=0; i<n; i++)
        {
            int rightMaxIdx = maxRight[i];
            int rightMaxEle = s[rightMaxIdx];

            if (s[i] < rightMaxEle)
            {
                swap(s[i], s[rightMaxIdx]);
                return stoi(s);
            }
        }

        return num;
    }
};