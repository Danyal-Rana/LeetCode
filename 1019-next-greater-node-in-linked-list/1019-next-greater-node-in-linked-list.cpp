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
    
    int myFun (ListNode *t, int myVal)
    {
        while (t->next != NULL)
        {
            if (t->next->val > myVal)
            {
                return t->next->val;
            }
            t = t->next;
        }
        return 0;       
        
    }
    vector<int> nextLargerNodes(ListNode* head)
    {
        
        ListNode *t = head;
        vector<int> myVector;
        
        while (t != NULL)
        {
            myVector.push_back (myFun(t, t->val));
            t = t->next;
        }
        
        
        return myVector;
    }
};