class Solution {
public:
    string frequencySort(string s) {
        vector<int>v1(123,0);
        vector<int>v2(123,0);
        for(int i=0;i<s.size();i++){
            v1[s[i]]++;
            v2[s[i]]++;
        }

        string str;
        sort(v2.begin(),v2.end());
        reverse(v2.begin(),v2.end());

        for(int i=0;i<123;i++){
            if(v2[i]>0){
                for(int j=0;j<123;j++){
                    if(v2[i]==v1[j]){
                        while(v1[j]--){
                            str.push_back((char)(j));
                        }
                    }
                }
            }
        }
        return str;
    }
};