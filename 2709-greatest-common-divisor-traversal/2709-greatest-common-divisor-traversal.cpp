const int mex = 1e5 + 5;

int par[mex];
int siz[mex];
int A[mex];

void init(int x)
{
    for (int i = 0; i <= x; ++i)
    {
        par[i] = i;
        siz[i] = 1;
        A[i] = 0;
    }

    for (int i = 2; i <= x; ++i)
    {
        if (A[i] == 0)
        {
            A[i] = i;
            for (int j = 2 * i; j <= x; j += i)
            {
                A[j] = i;
            }
        }
    }
}

int finder(int x)
{
    if (x == par[x]) return x;
    return par[x] = finder(par[x]);
}

void merge(int a, int b)
{
    int x1 = finder(a);
    int x2 = finder(b);
    if (x1 != x2)
    {
        par[x2] = x1;
        siz[x1] += siz[x2];
    }
}

class Solution
{
    public:
        bool canTraverseAllPairs(vector<int> &v)
        {
            int x = 0;
            if(v.size()==1)
                return true;
            for (auto i: v)
            {
                if (i == 1) return false;
                x = max(x, i);
            }
            init(x);

            for (auto i: v)
            {
                int x = i;
                while (x > 1)
                {
                    int p = A[x];
                    merge(i, p);
                    while (x % p == 0 && x > 1)
                        x /= p;
                }
            }

            int f = finder(v[0]);
            for (auto i: v)
                if (finder(i) != f)
                    return false;
            return true;
        }
};