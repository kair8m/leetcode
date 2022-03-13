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
        auto curr = head;
        unordered_map<int, ListNode*> nodes;
        int len = 0;
        while(curr) {
            nodes[len++] = curr;
            curr = curr->next;
        }
        int left = 0;
        int right = len - 1;
        while (left < right) {
            if (nodes[left]->val != nodes[right]->val)
                return false;
            left++;
            right--;
        }
        return true;
    }
};