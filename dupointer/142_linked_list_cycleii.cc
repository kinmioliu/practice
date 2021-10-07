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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (fast != NULL && fast != slow) {
            slow = slow->next;
            fast = fast->next;
            if (fast == NULL) {
                return NULL;
            }
            fast = fast->next;
        }
        if (fast == NULL) {
            return NULL;
        }
        slow = head;
        fast = fast->next;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
