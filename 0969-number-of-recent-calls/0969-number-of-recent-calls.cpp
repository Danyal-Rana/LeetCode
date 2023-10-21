class RecentCounter {
public:
    queue<int> myQueue;

    RecentCounter() {}
    
    int ping(int t)
    {
        myQueue.push (t);

        while (myQueue.front() < t-3000)
        {
            myQueue.pop();
        }

        return myQueue.size();      
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */