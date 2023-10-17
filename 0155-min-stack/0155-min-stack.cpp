class MinStack {
public:

    vector <pair<int, int> > myStack;
    MinStack() {}
    
    void push(int val)
    {
        if (myStack.empty())
        {
            pair <int, int> p;
            p.first = val;
            p.second = val;
            myStack.push_back (p);
        }
        else
        {
            pair <int, int> p;
            p.first = val;
            p.second = min(val, myStack.back().second);
            myStack.push_back (p);
        }
    }
    
    void pop()
    {
        return myStack.pop_back();        
    }
    
    int top()
    {
        return myStack.back().first;        
    }
    
    int getMin()
    {
        return myStack.back().second;        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */