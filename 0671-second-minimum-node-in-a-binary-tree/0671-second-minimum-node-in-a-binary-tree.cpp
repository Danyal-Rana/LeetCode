class Solution
{
public:
    
    void removeDuplicates(vector<int>& myVector)
    {
        set<int> uniqueElements;
        
        for (int element : myVector)
        {
            uniqueElements.insert(element);
        }

        myVector.clear();

        for (int element : uniqueElements)
        {
            myVector.push_back(element);
        }
    }
    
    
    void inOrder(TreeNode *root, vector<int> &myVector)
    {
        if (root == NULL)
        {
            return;
        }

        inOrder(root->left, myVector);

        myVector.push_back (root->val);

        inOrder(root->right, myVector);
    }

    int findSecondMinimumValue(TreeNode *root)
    {
        vector<int> myVector;

        inOrder(root, myVector);

        sort(myVector.begin(), myVector.end());
        
        removeDuplicates (myVector);

        if (myVector.size() >= 2)
        {
            return myVector[1];
        }

        return -1;
    }
};