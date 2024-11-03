class Solution {
public:
    bool rotateString(string s, string goal)
    {
        for (int i=0; i<s.size(); i++)
        {
            if (s == goal)
            {
                return true;
            }
            rotate(s.begin(), s.begin()+1 ,s.end());
        }

        return false;
    }
};