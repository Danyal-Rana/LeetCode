/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX, maxDist = INT_MIN;
        ListNode* prevNode = head;
        int currLoc = 0, minCriticLoc = INT_MAX, maxCriticLoc = INT_MIN;
        for (ListNode* currNode = head; currNode != nullptr; currNode = currNode->next) {
            currLoc++;
            if (currLoc > 1 && currNode->next != nullptr &&
                ((currNode->next->val < currNode->val && prevNode->val < currNode->val) ||
                 (currNode->next->val > currNode->val && prevNode->val > currNode->val))) {
                if (minCriticLoc != INT_MAX) {
                    minDist = min(minDist, currLoc - maxCriticLoc);
                    maxDist = max(maxDist, currLoc - minCriticLoc);
                }
                if (minCriticLoc == INT_MAX) {
                    minCriticLoc = currLoc;
                }
                maxCriticLoc = currLoc;
            }
            prevNode = currNode;
        }
        return {minDist == INT_MAX ? -1 : minDist, maxDist == INT_MIN ? -1 : maxDist};
    }
};