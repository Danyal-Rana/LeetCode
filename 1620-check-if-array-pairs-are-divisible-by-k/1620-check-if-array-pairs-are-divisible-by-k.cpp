class Solution{
public:
    bool canArrange(vector<int>& arr, int k)
    {
        vector<int> mp(k, 0);

        for (auto &num : arr)
        {
            int rem = (num % k + k) % k;
            mp[rem]++;
        }

        if (mp[0] % 2 != 0)
        {
            return false;
        }

        for (int rem = 1; rem < k; rem++)
        {
            int counterHalf = k - rem;

            if (mp[rem] != mp[counterHalf])
            {
                return false;
            }
        }

        return true;
    }
};