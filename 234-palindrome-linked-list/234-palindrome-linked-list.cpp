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
    bool isPalindrome(ListNode* head) {
        auto fastPtr = head;
        auto slowPtr = head;
        // find middle (slowPtr)
        while (fastPtr && fastPtr->next) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        // reverse second half
        ListNode* prev = nullptr;
        while (slowPtr) {
            auto node = slowPtr->next;
            slowPtr->next = prev;
            prev = slowPtr;
            slowPtr = node;
        }
        // check palidrome
        auto left = head;
        auto right = prev;
        while (right) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};