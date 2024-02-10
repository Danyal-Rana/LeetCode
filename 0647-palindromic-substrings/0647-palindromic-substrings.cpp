class Solution {
public:

    int exp(string s,int i ,int j ){
        int cnt = 0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        int n = s.length();
        for(int i = 0;i<n;i++){
            int oddans = exp(s,i,i);
            cnt = cnt + oddans;
            int evnans = exp(s,i,i+1);
            cnt = cnt + evnans;
        }
        return cnt;
    }
};