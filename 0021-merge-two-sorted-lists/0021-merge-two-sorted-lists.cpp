class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode *h1 = list1;
        ListNode *h2 = list2;
        ListNode *myHead = nullptr;
        ListNode *t1 = nullptr;

        if (!h1)
            return h2;
        if (!h2)
            return h1;

        if (h1->val < h2->val)
        {
            myHead = h1;
            h1 = h1->next;
        }
        else
        {
            myHead = h2;
            h2 = h2->next;
        }

        t1 = myHead;

        while (h1 != nullptr && h2 != nullptr)
        {
            if (h1->val < h2->val)
            {
                t1->next = h1;
                t1 = t1->next;
                h1 = h1->next;
            }
            else
            {
                t1->next = h2;
                t1 = t1->next;
                h2 = h2->next;
            }
        }

        if (h1 != nullptr)
        {
            t1->next = h1;
        }
        else
        {
            t1->next = h2;
        }

        return myHead;
    }
};