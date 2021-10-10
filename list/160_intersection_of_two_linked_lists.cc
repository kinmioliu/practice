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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        int nodeCntA = 0, nodeCntB = 0, diffCnt = 0;
        while (a != 0) {
            a = a->next;
            nodeCntA++;
        }
        while (b != NULL) {
            b = b->next;
            nodeCntB++;
        }
        a = headA;
        b = headB;
        
        if (nodeCntA > nodeCntB) {
            diffCnt = a - b;
            while (diffCnt) {
                a = a->next;
                diffCnt--;
            }
        } else {
            diffCnt = b - a;
            while (diffCnt) {
                b = b->next;
                diffCnt--;
            }
        }
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }
};

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        ListNode* a = headA;
        ListNode* b = headB;
        int nodeCntA = 1, nodeCntB = 1, diffCnt = 0;
        while (a->next != NULL) {
            a = a->next;
            nodeCntA++;
        }
        while (b->next != NULL) {
            b = b->next;
            nodeCntB++;
        }
        if (a != b) {
            return NULL; // no intersection
        }
        a = headA;
        b = headB;

        if (nodeCntA > nodeCntB) {
            diffCnt = nodeCntA - nodeCntB;
            while (diffCnt) {
                a = a->next;
                diffCnt--;
            }
        } else {
            diffCnt = nodeCntB - nodeCntA;
            while (diffCnt) {
                b = b->next;
                diffCnt--;
            }
        }
        while (a != b) {
            a = a->next;
            b = b->next;
        }
        return a;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;        
        // after a reach to end of headA, then begin from headB
        // if they have intersection, they will meet at c
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }    
    
};

