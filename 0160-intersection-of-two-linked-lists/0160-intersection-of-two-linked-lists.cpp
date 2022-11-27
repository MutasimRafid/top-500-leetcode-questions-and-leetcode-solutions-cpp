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
    //read note book and video to get clear idea about approaches
    
    //solution 1: using loop
    //Time Complexity: O(m*n) Reason: For each node in list 2 entire lists 1 are iterated. 
    //Space Complexity: O(1)  Reason: No extra space is used.
    /*
    node* intersectionPresent(node* head1,node* head2) {
     while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
      }
    //intersection is not present between the lists return null
    return NULL;
   }
    */
    
    
    //solution 2: hashing
    //Time Complexity:  O(n+m) Reason: Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m).  
    //Space Complexity: O(n)  Reason: Storing list 1 node addresses in unordered_set..
    /*
    node* intersectionPresent(node* head1,node* head2) {
     while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
      }
    //intersection is not present between the lists return null
    return NULL;
   }
    */
    
    //solution 3: optimized..two pointer approach
    /*Time Complexity: O(2*max(length of list1,length of list2))
    Reason: Uses the same concept of difference of lengths of two lists.
    Space Complexity: O(1)
    Reason: No extra data structure is used
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA, *b = headB;
        while(a != b){
            if(a==NULL) a = headB;
            else a = a->next;
            
            if(b == NULL) b = headA;
            else b = b->next;
        }
        return a; // even if head is null/ a and b are different(do not intersect), then also a        and b are null. so return a is ok 
    }
};