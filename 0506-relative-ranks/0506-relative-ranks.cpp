#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        vector<int> arr = score;
        sort(arr.begin(), arr.end(), greater<int>());
        
        vector<string> ans(score.size());
        
        for (int i = 0; i < score.size(); i++) 
        {
            if (score[i] == arr[0])
                ans[i] = "Gold Medal";
            else if (score[i] == arr[1])
                ans[i] = "Silver Medal";
            else if (score[i] == arr[2])
                ans[i] = "Bronze Medal";
            else
                ans[i] = to_string(find(arr.begin(), arr.end(), score[i]) - arr.begin() + 1);
        }
        
        return ans;
    }
};