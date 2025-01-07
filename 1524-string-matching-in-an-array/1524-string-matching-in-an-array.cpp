class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> matchingWords;

        for (int currentWordIndex = 0; currentWordIndex < words.size(); currentWordIndex++)
        {
            for (int otherWordIndex = 0; otherWordIndex < words.size(); otherWordIndex++) 
            {
                if (currentWordIndex == otherWordIndex)
                    continue;

                if (isSubstringOf(words[currentWordIndex], words[otherWordIndex]))
                {
                    matchingWords.push_back(words[currentWordIndex]);
                    break;
                }
            }
        }

        return matchingWords;
    }

private:
    bool isSubstringOf(string &sub, string &main) 
    {
        for (int startIndex = 0; startIndex < main.size(); startIndex++) 
        {
            bool subFits = true;

            for (int subIndex = 0; subIndex < sub.size(); subIndex++) 
            {
                if (startIndex + subIndex >= main.size() || main[startIndex + subIndex] != sub[subIndex]) 
                {
                    subFits = false; 
                    break;
                }
            }

            if (subFits) 
            {
                return true;
            }
        }

        return false;
    }
};