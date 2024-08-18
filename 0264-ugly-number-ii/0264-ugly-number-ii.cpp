class Solution {
public:
    int nthUglyNumber(int n)
    {
        vector<int> arr(n+1);

        int i2;
        int i3;
        int i5;

        i2 = i3 = i5 = 1;

        arr[1] = 1;

        for (int i=2; i<=n; i++)
        {
            int i2Ugly = arr[i2]*2;

            int i3Ugly = arr[i3]*3;

            int i5Ugly = arr[i5]*5;

            int minUgly = min ({i2Ugly, i3Ugly, i5Ugly});

            arr[i] = minUgly;

            if (minUgly == i2Ugly)
            {
                i2++;
            }
            if (minUgly == i3Ugly)
            {
                i3++;
            }
            if (minUgly == i5Ugly)
            {
                i5++;
            }
        }

        return arr[n];
    }
};