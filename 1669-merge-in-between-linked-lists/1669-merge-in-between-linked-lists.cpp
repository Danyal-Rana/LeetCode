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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        ListNode *curNode = list1;
        int index = 0;
        
        while (index < a-1)
        {
            curNode = curNode->next;
            index++;
        }
        ListNode *aNode = curNode;
        
        while (index < b+1)
        {
            curNode = curNode->next;
            index++;
        }
        ListNode *bNode = curNode;
        
        ListNode *list2Head = list2;
        ListNode *list2Tail = list2;
        
        while (list2Tail->next != NULL)
        {
            list2Tail = list2Tail->next;
        }
        
        aNode->next = list2Head;
        list2Tail->next = bNode;
        
        return list1;
    }
};