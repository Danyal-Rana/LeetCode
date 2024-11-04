class Solution {
public:
    string compressedString(string word)
    {
        int n = word.size();
        string ans = "";

        int i=0;

        while (i<n)
        {
            int counter = 0;
            char ch = word[i];

            while (i<n && counter<9 && word[i]==ch)
            {
                counter++;
                i++;
            }

            ans += to_string(counter) + ch;
        }

        return ans;
    }
};