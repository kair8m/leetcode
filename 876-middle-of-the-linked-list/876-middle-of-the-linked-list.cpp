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
    ListNode* middleNode(ListNode* head) {
        auto slowPtr = head;
        auto fastPtr = head;
        auto prev = slowPtr;
        int len = 0;
        while (fastPtr) {
            prev = slowPtr;
            slowPtr = slowPtr->next;
            auto node = fastPtr->next;
            len++;
            if (!node)
                break;
            fastPtr = node->next;
            len++;
        }
        return len % 2 == 0 ? slowPtr : prev;
    }
};