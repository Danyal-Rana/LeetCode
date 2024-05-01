class Solution {
public:
    string reversePrefix(string word, char ch)
    {
        int flag = -1;
        
        for (int i=0; i<word.size(); i++)
        {
            if (word[i] == ch)
            {
                flag = i+1;
                break;
            }
        }
        
        if (flag != -1)
        {
            reverse(word.begin(), word.begin()+flag);
        }
        
        return word;
    }
};