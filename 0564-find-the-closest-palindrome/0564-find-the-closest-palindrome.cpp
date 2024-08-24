class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        if (len == 1) {
            return to_string(stoi(n) - 1);  // Agar single-digit number hai toh usse 1 kam karke return kar do
        }

        // Yeh saare possible palindromes hain jo closest ho sakte hain
        vector<long long> candidates;
        
        // 1. Sabse bada number jo ek digit kam ka ho (999...999)
        candidates.push_back(pow(10, len - 1) - 1);  // Example: 999 for 1000
        
        // 2. Sabse chhota number jo ek digit zyada ka ho (1000...0001)
        candidates.push_back(pow(10, len) + 1);  // Example: 10001 for 9999

        // 3. Palindrome banao first half ko mirror karke
        long long prefix = stoll(n.substr(0, (len + 1) / 2));  // Number ke first half ka prefix le lo

        // Prefix ko thoda adjust karke variations banao
        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);  // Prefix ko increment ya decrement karo
            string candidate = p + string(p.rbegin() + (len % 2), p.rend());  // Mirror karke palindrome banao
            candidates.push_back(stoll(candidate));  // Palindrome ko candidates mein daal do
        }

        // Original number ko long long mein convert kar lo comparison ke liye
        long long num = stoll(n);

        // Initialize karo closest palindrome ko
        long long closest = -1;

        for (long long cand : candidates) {
            if (cand == num) continue;  // Agar candidate original number jaisa hai, toh usko skip kar do
            if (closest == -1 ||
                abs(cand - num) < abs(closest - num) ||  // Jo candidate closest ho, usko update kar do
                (abs(cand - num) == abs(closest - num) && cand < closest)) {  // Agar distance same hai, toh chhota candidate choose karo
                closest = cand;
            }
        }

        return to_string(closest);  // Closest palindrome ko string mein convert karke return kar do
    }
};