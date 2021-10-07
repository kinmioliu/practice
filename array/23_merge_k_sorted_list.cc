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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* left, ListNode* right) {return left->val < right->val;}
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp) > minq;
        // 1. for each head_node in lists, insert to minq
        // 2. then take head and insert head->next, if head->next null, then do nothing
        // 3. while step 2 until all node are take from minq
        for (auto node : lists) {
            minq.push(node);
        }
        ListNode* newList = NULL, newListTail = NULL;
        
        while (minq.empty()) {
            if (newList == NULL) {
                newList = minq.top();
                newListTail = newList;
            } else {
                newListTail->next = minq.top();
                newListTail = newListTail->next;
            }
            minq.pop();
            if (newListTail->next != NULL) {
                minq.push(newListTail->next);
            }
        }
        return newList;
    }
};
