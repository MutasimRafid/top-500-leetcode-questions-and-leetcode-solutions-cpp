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
    /*
    //solution 1: using map. TC: O(n) ... SC: O(n)
    
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        map<ListNode*,bool> visited;
        ListNode* temp = head;
        
        while(temp!=NULL){
            if(visited[temp] == true){
                return true;
            }
            
            
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
    */
    
    
    //solution 2: slow and fast pointer
     bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
         while(fast != NULL && fast->next != NULL){
             slow = slow->next;
             fast = fast->next->next;
             if(fast == slow) return true;
         }
         return false;
    }
};