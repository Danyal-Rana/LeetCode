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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode *t = new ListNode (0);
        t->next = head;
        ListNode *p = t;
        ListNode *c = head;

        while (c != NULL)
        {
            if (c->val == val)
            {
                p->next = c->next;
                delete c;
                c = p->next;
            }
            else
            {
                p = c;
                c = c->next;
            }
        }
        head = t->next;
        delete t;
        return head;
    }
};