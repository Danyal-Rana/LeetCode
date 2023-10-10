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
    bool isPalindrome(ListNode* head)
    {
        vector<int> myVector;
        
        ListNode *p = head;
        
        while (p != NULL)
        {
            myVector.push_back (p->val);
            p = p->next;
        }
        
        for (int i=0, j=myVector.size()-1; i<j; i++,j--)
        {
            if (myVector[i] != myVector[j])
            {
                return false;
            }
        }
        return true;
    }
};