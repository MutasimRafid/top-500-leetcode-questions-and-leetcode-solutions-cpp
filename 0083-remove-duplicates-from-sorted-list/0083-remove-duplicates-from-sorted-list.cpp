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
    
    //Solution 1: Recursive solution:
    //Recursion TC - O(N)
    //Recursion SC - O(N) because function is called n times in worst case
    /*
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
    */
    
    //solution 2: iterative solution: 
    //Iteration TC - O(N)
    //Iteration SC - O(1)

    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        while(temp->next != NULL){
            if(temp->val == temp->next->val){
                ListNode*del = temp->next;
                temp->next = del->next; //skipping duplicate value
                delete del;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};