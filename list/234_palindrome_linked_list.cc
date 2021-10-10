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
        int nodeCnt = 0;
        ListNode* cur = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        while (cur != NULL) {
            cur = cur->next;
            nodeCnt++;
        }
        if (nodeCnt == 1) {
            return true;
        }
        int midPos = nodeCnt / 2;
        cur = head;        
        // reverse to midPos
        while (midPos) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            midPos--;
        }
        //cout << cur->val << endl;
        if (nodeCnt % 2 == 0) {
            prev = prev;
        } else {
            next = next->next;
        }
        while (next != NULL) {
            if (next->val != prev->val) {
                return false;
            }
            next = next->next;
            prev = prev->next;
        }
        return true;
    }
};
