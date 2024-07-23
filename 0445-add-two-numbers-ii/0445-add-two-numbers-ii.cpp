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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> s1, s2;

        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int sum = 0;
        int carry = 0;
        ListNode *ans = new ListNode();

        while (!s1.empty() || !s2.empty())
        {
            if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }

            ans->val = sum % 10;
            carry = sum / 10;
            ListNode *temp = new ListNode(carry);
            temp->next = ans;
            ans = temp;
            sum = carry;
        }

        return carry==0 ? ans->next : ans;
    }
};