class Solution {
public:
    bool canConstruct(string s, int k) {
        // Handle edge cases
        if (s.length() < k) return false;
        if (s.length() == k) return true;

        // Initialize frequency array and oddCount integer
        vector<int> freq(26);
        int oddCount = 0;

        // Increment the value of the index corresponding to the current
        // character
        for (auto& chr : s) freq[chr - 'a']++;

        // Count the number of characters that appear an odd number of times in
        // s
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
            }
        }

        // Return if the number of odd frequencies is less than or equal to k
        return (oddCount <= k);
    }
};