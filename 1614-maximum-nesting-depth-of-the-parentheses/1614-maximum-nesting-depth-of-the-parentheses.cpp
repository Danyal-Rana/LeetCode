
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> myStack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                myStack.push(s[i]);
                ans = max(ans, (int)myStack.size());
            } else if (s[i] == ')') {
                if (!myStack.empty()) {
                    myStack.pop();
                } else {
                    return -1;
                }
            }
        }
        
        if (!myStack.empty()) {
            return -1; 
        }

        return ans;
    }
};