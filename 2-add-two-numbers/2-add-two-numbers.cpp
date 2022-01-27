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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* current = result;
        while (l1 || l2)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int result = val1 + val2;
            cout << "val1 " << val1 << " val2 " << val2 << " result " << result << endl;
            current->val += result % 10;
            int remainder = current->val / 10;
            current->val = current->val % 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            result = result / 10 + remainder;
            if (!l1 && !l2 && result == 0)
                break;
            if (!current->next)
                current->next = new ListNode(result);
            current = current->next;
        }
        return result;
    }
};