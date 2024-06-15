class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        int n = profits.size();
        typedef pair<int, int> pi;
        vector<pi> projects;

        for (int i = 0; i < n; i++) 
        {
            projects.push_back({profits[i], capital[i]});
        }

        sort(projects.begin(), projects.end(), [&](pi a, pi b) 
        {
            return a.second < b.second;
        });

        priority_queue<int> pq;
        int i = 0;

        while (k > 0) {
            while (i < n && projects[i].second <= w) 
            {
                pq.push(projects[i].first);
                i++;
            }

            if (!pq.empty()) 
            {
                w += pq.top();
                pq.pop();
            }
            k--;
        }

        return w;
    }
};
