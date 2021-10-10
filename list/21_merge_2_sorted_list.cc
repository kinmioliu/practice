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
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* merged = l1->val < l2->val ? l1 : l2;
        ListNode* compared = merged == l1 ? l2 : l1;
        ListNode* mp = merged, *cp = compared;
        ListNode* tmp;
        while (mp != NULL && cp != NULL) {
            if (mp->val <= cp->val) {
                //
                while (mp->next != NULL && mp->next->val <= cp->val) {
                    mp = mp->next;
                }
                // splic cp to merged list
                tmp = cp->next;
                cp->next = mp->next;
                mp->next = cp;
                mp = cp;
                cp = tmp;
            } else {
                if (mp->next == NULL) {
                    mp->next = cp;
                    return merged;
                }
                mp = mp->next;
            }
        }
        return merged;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head;
        ListNode* node = &head;
        while(l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                node->next = l1;
                node = l1;
                l1 = l1->next;
            } else {
                node->next = l2;
                node = l2;
                l2 = l2->next;
            }
        }
        node->next = l1 == NULL ? l2 : l1;
        return head.next;
    }    
};
