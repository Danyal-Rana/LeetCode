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
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_set<int> mySet;

        for (auto n : nums)
        {
            mySet.insert(n);
        }

        ListNode *dummyHead = new ListNode();
        ListNode *h2 = dummyHead;

        ListNode *itr = head;

        while (itr)
        {
            if (mySet.find(itr->val) == mySet.end())
            {
                ListNode *temp = new ListNode (itr->val);
                h2->next = temp;
                h2 = temp;
            }
            itr = itr->next;
        }

        return dummyHead->next;
    }
};