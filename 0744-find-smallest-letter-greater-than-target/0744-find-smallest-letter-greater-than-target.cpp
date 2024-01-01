class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        char ans = letters[0];
        int mini = INT_MAX;
        
        for (int i=0; i<letters.size(); i++)
        {
            int cMini = (letters[i]+'0')-(target+'0');
            
            if (letters[i]>target && cMini<mini)
            {
                mini = cMini;
                ans = letters[i];
            }
        }
        
        return ans;
    }
};