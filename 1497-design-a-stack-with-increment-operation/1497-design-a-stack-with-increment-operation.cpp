class CustomStack {
public:

    vector<int> myStack;
    vector<int> increments;
    int n;

    CustomStack(int maxSize)
    {
        n = maxSize;
    }
    
    void push(int x)
    {
        if (myStack.size() < n)
        {
            myStack.push_back(x);
            increments.push_back(0);
        }        
    }
    
    int pop()
    {
        if (myStack.size() == 0)
        {
            return -1;
        }

        int idx = myStack.size()-1;
        if (idx > 0)
        {
            increments[idx-1] += increments[idx]; // lazy propagation
        }

        int topValue = myStack[idx] + increments[idx];
        myStack.pop_back();
        increments.pop_back();

        return topValue;
    }
    
    void increment(int k, int val)
    {
        int idx = min(k, static_cast<int>(myStack.size()));

        if (idx > 0)
        {
            increments[idx - 1] += val;
        }
}

};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */