class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        int n = arr.size();
        
        priority_queue<pair<double, pair<int, int>>> pq;
        
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                double myFraction = (1.0*arr[i]) /arr[j];
                
                if (pq.size()==k)
                {
                    if ( myFraction < pq.top().first)
                    {
                        pq.pop();
                        pq.push({myFraction, {arr[i], arr[j]}});
                    }
                }
                else
                {
                    pq.push({myFraction, {arr[i], arr[j]}});
                }
            }
        }
        
        return {pq.top().second.first, pq.top().second.second};
    }
};