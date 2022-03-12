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
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        ListNode* fastPtr = head;
        ListNode* slowPtr = head;
        do {
            slowPtr = slowPtr->next;
            auto next = fastPtr->next;
            if (!next)
                return false;
            fastPtr = next->next;
        } while (fastPtr != slowPtr && fastPtr && slowPtr);
        
        return fastPtr == slowPtr;
    }
};