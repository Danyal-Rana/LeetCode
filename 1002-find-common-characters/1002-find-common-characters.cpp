class Solution {
public:
    vector<string> commonChars(vector<string>& a) {
        vector<int> res(26, INT_MAX);

        for(int i=0;i<a.size();i++) {
            vector<int> count(26, 0);
            for(int j=0;j<a[i].size();j++) count[a[i][j]-'a']++;
            for(int j=0;j<26;j++)res[j]=min(res[j], count[j]);
        }

        vector<string> resArray;
        for(int i=0;i<26;i++) {
            while(res[i]!=0) {
                resArray.push_back(string(1, 'a' + i));
                res[i]--;
            }
        }
        return resArray;
    }
};