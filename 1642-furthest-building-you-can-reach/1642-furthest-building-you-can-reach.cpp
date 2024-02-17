class Solution {
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        std::priority_queue<int> minHeap;

        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1] - heights[i];

            if (diff > 0) {
                if (ladders > 0) {
                    minHeap.push(-diff);
                    ladders--;
                } else if (!minHeap.empty() && -minHeap.top() < diff) {
                    bricks += minHeap.top();
                    minHeap.pop();
                    minHeap.push(-diff);
                } else {
                    bricks -= diff;
                }

                if (bricks < 0) {
                    return i;
                }
            }
        }

        return heights.size() - 1;
    }
};