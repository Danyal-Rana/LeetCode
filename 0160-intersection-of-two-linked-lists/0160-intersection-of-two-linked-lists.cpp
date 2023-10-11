/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength (ListNode *x)
    {
        int myCounter = 0;
        
        while (x != NULL)
        {
            myCounter++;
            x = x->next;
        }
        return myCounter;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        
        int len1 = getLength (headA);
        int len2 = getLength (headB);
        
        while (len1 > len2)
        {
            len1--;
            t1 = t1->next;
        }
        
        while (len2 > len1)
        {
            len2--;
            t2 = t2->next;
        }
        
        while (t1 != t2)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        
        if (t1 == t2)
        {
            return t1;
        }
        return NULL;
        
    }
};