class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int points = 0;

        // Helper function to remove the specific substring and calculate points
        auto removeSubstring = [&](char first, char second, int pointsValue) {
            stack<char> st;
            int localPoints = 0;
            for (char c : s) {
                if (!st.empty() && st.top() == first && c == second) {
                    st.pop();
                    localPoints += pointsValue;
                } else {
                    st.push(c);
                }
            }
            // Reconstruct the string from the stack
            s = "";
            while (!st.empty()) {
                s += st.top();
                st.pop();
            }
            reverse(s.begin(), s.end());
            return localPoints;
        };

        if (x > y) {
            points += removeSubstring('a', 'b', x);
            points += removeSubstring('b', 'a', y);
        } else {
            points += removeSubstring('b', 'a', y);
            points += removeSubstring('a', 'b', x);
        }

        return points;
    }
};