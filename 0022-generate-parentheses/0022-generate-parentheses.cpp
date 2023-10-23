class Solution {
public:
    
    void myFun (vector<string> &myVector, int n, int openingBrac, int closingBrac, string myStr)
    {
        if (myStr.size() == n*2)
        {
            myVector.push_back (myStr);
            return;
        }
        
        if (openingBrac < n)
        {
            myFun (myVector, n, openingBrac+1, closingBrac, myStr+"(");
        }
        
        if (closingBrac < openingBrac)
        {
            myFun (myVector, n, openingBrac, closingBrac+1, myStr+")");
        }
    }
    
    vector<string> generateParenthesis(int n)
    {
        vector<string> myVector;
        myFun (myVector, n, 0, 0, "");
        return myVector;
    }
};