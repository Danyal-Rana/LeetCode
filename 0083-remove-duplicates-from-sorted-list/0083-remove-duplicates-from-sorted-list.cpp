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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }        

        ListNode *d = new ListNode (0);
        d->next = head;
        ListNode *p = d;
        ListNode *c = head;

        while (c != NULL)
        {
            if (c->next!=NULL && c->val == c->next->val)
            {
                ListNode *del = c;
                c = c->next;
                p->next = c;
                delete del;
            }
            else
            {
                p = c;
                c = c->next;
            }
        }
        head = d->next;
        delete d;

        return head;
    }
};