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
    ListNode* reverseListIterative(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* reverseList(ListNode* head) {
        // return reverseListIterative(head);
        return reverseListRecursive(head, nullptr);
    }
    
    ListNode* reverseListRecursive(ListNode* node, ListNode* prev) {
        if (!node)
            return prev;
        auto next = node->next;
        node->next = prev;
        prev = node;
        node = next;
        return reverseListRecursive(node, prev);
    }
};