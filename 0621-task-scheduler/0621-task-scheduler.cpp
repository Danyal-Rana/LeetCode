class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> myMap;
        for (auto i : tasks)
        {
            myMap[i]++;
        }
        
        priority_queue<int> pq;
        for (auto i : myMap)
        {
            pq.push(i.second);
        }
        
        int result = 0;
        while (!pq.empty())
        {
            int time = 0;
            vector<int> tmp;
            
            for (int i=0; i<n+1; i++)
            {
                if (!pq.empty())
                {
                    tmp.push_back (pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for (auto i : tmp)
            {
                if (i)
                {
                    pq.push (i);
                }
            }
            
            result += pq.empty() ? time : n+1;
        }
        return result;
    }
};