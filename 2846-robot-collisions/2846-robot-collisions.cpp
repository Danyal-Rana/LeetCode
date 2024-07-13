class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string direction) {

        vector<pair<int, int>> v;
        vector<int> ans;
        int np = positions.size();
        for (int i = 0; i < positions.size(); i++) {
            v.push_back(make_pair(positions[i], i));
        }
        sort(v.begin(), v.end());
        stack<int> st;
        st.push(v[0].second);
        for (int k = 1; k < v.size(); k++) {
            int i = v[k].second;
            if(!st.empty()){
                int temp = st.top();
                if (direction[i] == 'L' && direction[temp] == 'R') {
                    if (healths[i] == healths[temp]) {
                        st.pop();
                    } else if (healths[i] > healths[temp]) {
                        healths[i]--;
                        st.pop();
                        k--;
                    } else if (healths[i] < healths[temp]) {
                        healths[temp]--;
                    }
                } else {
                    st.push(i);
                }
            }
            else st.push(i);
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = healths[ans[i]];
        }
        return ans;
    }
};