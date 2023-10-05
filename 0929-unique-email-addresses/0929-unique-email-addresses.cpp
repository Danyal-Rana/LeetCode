class Solution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        set <string> mySet;

        for (const string &email : emails)
        {
            string localName;

            for (const char c : email)
            {
                if (c == '+' || c == '@')
                {
                    break;
                }
                else if (c == '.')
                {
                    continue;
                }
                localName = localName + c;
            }
            string atDomain = email.substr (email.find('@'));
            mySet.insert (localName + atDomain);
        }
        return mySet.size();
    }
};