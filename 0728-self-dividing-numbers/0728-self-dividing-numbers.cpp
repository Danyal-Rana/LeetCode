class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector <int> myVector;

        for (int i=left; i<=right; i++)
        {
            int temp = i;

            int flag = 1;

            while (temp > 0)
            {
                int digit = temp%10;

                if (digit==0 || i%digit != 0)
                {
                    flag = 0;
                    break;
                }
                temp = temp/10;
            }
            if (flag == 1)
            {
                myVector.push_back (i);
            }
        }
        return myVector;        
    }
};