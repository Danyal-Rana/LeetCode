class Solution {
public:
    int n;
    int WIDTH;
    int t[1001][1001];
    int solve(vector<vector<int>>& books, int i, int remainW, int maxHt) {
        if(i >= n) {
            return maxHt;
        }

        if(t[i][remainW] != -1) {
            return t[i][remainW];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        //keep
        if(bookW <= remainW) { //let's keep it here
            keep = solve(books, i+1, remainW - bookW, max(maxHt, bookH));
        }

        //skip and put in next shelf
        skip = maxHt + solve(books, i+1, WIDTH - bookW, bookH);

        return t[i][remainW] = min(keep, skip);
    }


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(t, -1, sizeof(t));
        n = books.size();
        WIDTH = shelfWidth;

        int remainW = shelfWidth;
        return solve(books, 0, remainW, 0);
    }
};