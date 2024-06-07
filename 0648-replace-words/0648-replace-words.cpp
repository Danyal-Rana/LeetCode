class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence)
    {
        set<string> mySet;

        for (auto i : dictionary)
        {
            mySet.insert(i);
        }        

        string ans = "";

        sentence.push_back(' '); // to access last word of sentence

        string temp = "";

        for (int i=0; i<sentence.size(); i++)
        {
            if (sentence[i]==' ')
            {
                ans += temp;
                ans += " ";
                temp = "";
            }
            else
            {
                temp += sentence[i];

                if (mySet.count(temp))
                {
                    ans += temp;
                    ans += " ";
                    temp = "";

                    while (sentence[i] != ' ')
                    {
                        i++;
                    }
                }
            }
        }

        ans.pop_back();

        return ans;
    }
};