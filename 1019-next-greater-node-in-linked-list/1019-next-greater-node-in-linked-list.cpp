/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head)
    {
        vector<int> myVector;
        vector<int> input;
        stack<int> myStack;
        
        while (head != NULL)
        {
            input.push_back (head->val);
            head = head->next;
        }
        
        for (int i=input.size()-1; i>=0; i--)
        {
            while (!myStack.empty() && myStack.top() <= input[i])
            {
                myStack.pop();
            }
            
            if (myStack.empty())
            {
                myVector.push_back (0);
            }
            
            else
            {
                myVector.push_back (myStack.top());
            }
            
            myStack.push (input[i]);
        }
        
        reverse(myVector.begin(), myVector.end());
        return myVector;
    }
};