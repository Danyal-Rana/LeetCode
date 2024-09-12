class Solution {
public:

    bool sub(set<char> s, set<char> m)
    {
        for (auto c : m)
        {
            if (s.find(c)==s.end())
            {
                return 0;
            }
        }

        return 1;
    }
    
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        set<char> s(allowed.begin(), allowed.end());

        int myCounter = 0;

        for (auto w : words)
        {
            set<char> m(w.begin(), w.end());
            {
                if (sub(s, m))
                {
                    myCounter++;
                }
            }
        }

        return myCounter;
    }
};