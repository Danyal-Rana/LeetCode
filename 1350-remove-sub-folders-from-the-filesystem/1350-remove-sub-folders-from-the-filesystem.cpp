class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        unordered_set<string> st(folder.begin(), folder.end());
        vector<string> ans;

        for (auto currFolder : folder)
        {
            bool isSubFolder = false;
            string tempFolder = currFolder;

            while (!currFolder.empty())
            {
                size_t position = currFolder.find_last_of('/');

                currFolder = currFolder.substr(0, position);

                if (st.find(currFolder) != st.end())
                {
                    isSubFolder = true;
                    break;
                }
            }

            if (!isSubFolder)
            {
                ans.push_back(tempFolder);
            }
        }

        return ans;
    }
};