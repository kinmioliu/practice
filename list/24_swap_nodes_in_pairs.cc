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
    ListNode* swapPairs1(ListNode* head) {
        // 0 or 1 node
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* node = head->next;
        ListNode* prev = head;
        ListNode* cur = node;
        while (prev != NULL && cur != NULL) {
            // swap
            prev->next = cur->next;
            cur->next = prev;
            // reset prev and cur            
            prev = prev->next;
            if (prev == NULL) {
                break;
            }
            cur = prev->next;
            cout << prev->val << " " << cur->val << "|";
        }
        return node;
    }
    ListNode* swapPairs(ListNode* head) {
        // 0 or 1 node
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode node(0);
        ListNode* prev = &node;
        ListNode* cur = head;
        ListNode* next = head->next;
        while (cur != NULL && next != NULL) {
            // swap
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
            // reset prev and cur            
            prev = cur;
            cur = cur->next;
            if (cur == NULL) {
                break;
            }
            next = cur->next;
        }
        return node.next;
    }
    
};
