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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode *curr = head;
        ListNode *nextOfCurr = curr->next;

        while (curr && nextOfCurr)
        {
            ListNode *gcdNode = new ListNode();
            gcdNode->val = getGCD(curr->val, nextOfCurr->val);

            curr->next = gcdNode;
            gcdNode->next = nextOfCurr;
            curr = nextOfCurr;
            nextOfCurr = curr->next;            
        }

        return head;
    }

    int getGCD (int x, int y)
    {

        for (int i=min(x, y); i>=1; i--)
        {
            if (x%i==0 && y%i==0)
            {
                return i;
            }
        }

        return 1;
    }
};