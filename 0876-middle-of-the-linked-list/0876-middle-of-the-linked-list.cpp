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
    ListNode* middleNode(ListNode* head) {
        //solution 1: TC: O(N).. but using 2 iteration
        /*
        int n = 0;//size of linked list
        ListNode* temp = head;
        //traversing linked list
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        int half = n/2;
        temp = head;
        while(half--){
            temp = temp->next;
        }
        return temp;
        */


        //solution 2: optimized
        //slow and fast pointer: using only 1 iteration
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};