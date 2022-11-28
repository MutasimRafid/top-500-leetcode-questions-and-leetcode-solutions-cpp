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
    /*
    //solution 1: using dummy node
    //TC: O(n).. SC: O(n)
    ListNode* removeElements(ListNode* head, int val) {
      
        if(head == NULL) return NULL;
        ListNode *dummy = new ListNode(-1) ;
        dummy -> next = head ;
        
        // Tail initally points to Dummy
        ListNode *tail = dummy ;
        
        while(tail != NULL && tail -> next != NULL)
        {
            // If Tail's Next is equal to Val(key)
            
            if(tail -> next -> val == val)
            {
                // We make Temp point to Tail's Next Node
                
                ListNode *temp = tail -> next ;
                
                tail -> next = temp -> next ;
                
                // And then delete temp
                
                delete temp ;
            }
            
            // Else the values are not equal, so we make Tail move to Tail's Next Node
            
            else
            {
                tail = tail -> next ;
            }
        }
        
        // At the end, we return Dummy's Next which points to  LinkedList after removing all occurrences of Val(key)
        
        return dummy -> next ;    
    }
    */
    
    //solution 2: using recursion
    //TC: O(N)  SC:O(N) Auxillary stack space
     ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
         //recursion
         head->next = removeElements(head->next,val);
         if(head->val == val){
             ListNode* ans = head->next;
             delete head;
             return ans;
         }
         else{
             return head;
         }
    }
};