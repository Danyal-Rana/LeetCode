class Solution {
public:
    int findLargestAreaInHistogram(int n, vector<int>& rowHistogram) {
        int area = 0;
        for (int i = 0; i < n; i++) {
            int breadth = 1;
            // first find only this area
            area = max(area, rowHistogram[i] * breadth);
            // now start checking for other lengths as well
            // as we might need other heights for more area

            // first check for heights behind it
            for (int j = i - 1; j >= 0; j--) {
                if (rowHistogram[j] >= rowHistogram[i]) {
                    breadth++;
                } else {
                    break;
                }
            }

            // now check for heights after it
            for (int j = i + 1; j < n; j++) {
                if (rowHistogram[j] >= rowHistogram[i]) {
                    breadth++;
                } else {
                    break;
                }
            }

            // now compute the area
            area = max(area, rowHistogram[i] * breadth);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int area = 0;
        // first make the histogram row wise
        vector<int> rowHistogram(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    rowHistogram[j]++;
                } else {
                    rowHistogram[j] = 0;
                }
            }
            area = max(area, findLargestAreaInHistogram(m, rowHistogram));
        }
        return area;
    }
};