class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        int wordCounter = 1;
        int n = sentence.size();
        int m = searchWord.size();
        bool flag = true;
        
        for (int i = 0; i < n; i++) 
        {
            int j = 0;
            string temp = "";

            if (sentence[i]==' ')
            {
                wordCounter++;
                flag = true;
                continue;
            }
            
            while (i < n && j < m && sentence[i] == searchWord[j] && flag) 
            {
                temp += sentence[i];
                i++;
                j++;

                if (sentence[i]==' ')
                {
                    i--;
                    continue;
                }
            }

            if (temp == searchWord)
            {
                return wordCounter;
            }
            flag = false;
        }
        
        return -1;
    }
};