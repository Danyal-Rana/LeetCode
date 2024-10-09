class Solution {
public:
    int minAddToMakeValid(string s)
    {
        int size = 0;
        int open = 0;

        for (auto &ch : s)
        {
            if (ch == '(')
            {
                size++;
            }
            else if (size > 0)
            {
                size--;
            }
            else
            {
                open++;
            }
        }

        return size+open;
    }
};