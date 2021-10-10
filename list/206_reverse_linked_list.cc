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
    ListNode* reverseList1(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *curNode = head->next;
        ListNode *tmpNode, *prevNode;
        prevNode = head;
        head->next = NULL;
        while (curNode != NULL) {
            tmpNode = curNode;
            curNode = curNode->next;
            tmpNode->next = prevNode;
            prevNode = tmpNode;
        }
        return tmpNode;
    }
    
    ListNode* reverseList2(ListNode* head) {
        ListNode *curNode = head;
        ListNode *prevNode = NULL, *nextNode = NULL;
        while (curNode != NULL) {
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        return prevNode;
    }    
    
    ListNode* reverseList(ListNode* head, ListNode* prev = NULL)
    {
        if (head == NULL) {
            return prev;
        }
        ListNode* next = head->next;
        head->next = prev;
        return reverseList(next, head);                
    }
    
    ListNode* reverseListRecursion(ListNode* head, ListNode* prev)
    {
        if (head == NULL) {
            return prev;
        }
        ListNode* next = head->next;
        head->next = prev;
        return reverseListRecursion(next, head);                
    }
    
    ListNode* reverseList3(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* next = head->next;
        head->next = NULL;
        return reverseListRecursion(next, head);
    }
};
