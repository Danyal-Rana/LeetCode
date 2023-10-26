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
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode *dummyHead = new ListNode (0);
        dummyHead->next = head;
        
        ListNode *nodeFromStart = dummyHead;
        
        int myCounter = 0;
        
        while (myCounter < k)
        {
            nodeFromStart = nodeFromStart->next;
            myCounter++;
        }
        
        ListNode *hare = nodeFromStart;
        ListNode *nodeFromEnd = dummyHead;
        
        while (hare != NULL)
        {
            hare = hare->next;
            nodeFromEnd = nodeFromEnd->next;
        }
        
        int temp = nodeFromStart->val;
        nodeFromStart->val = nodeFromEnd->val;
        nodeFromEnd->val = temp;        
        
        return dummyHead->next;
    }
};