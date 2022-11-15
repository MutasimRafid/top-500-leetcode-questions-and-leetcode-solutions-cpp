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
   //solution 1: iterative method
    /*
    ListNode* reverseList(ListNode* head) {
        //solution iterative method
        if(head == NULL) return NULL;
        ListNode *p = NULL, *c = head, *n = head->next;
        
        while(c != NULL){
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL) n = n->next;
        }
        return p;
    }
    */
    
    
    //solution 2: Recursive method
    ListNode* reverseList(ListNode* head) {
        //Base case
        if(head==NULL || head->next==NULL){
           return head;
        }
        
        ListNode* rest_head = reverseList(head->next);
        ListNode* rest_tail = head->next;
        rest_tail->next = head;
        head->next = NULL;
        return rest_head;
    }
};