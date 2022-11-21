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
    //Solution 1: Recursive solution
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        //recursive call
        ListNode* newHead = deleteDuplicates(head->next);
        if(head->val == newHead->val) return newHead;
        else{
            head->next = newHead;
            return head;
        }
    }
};