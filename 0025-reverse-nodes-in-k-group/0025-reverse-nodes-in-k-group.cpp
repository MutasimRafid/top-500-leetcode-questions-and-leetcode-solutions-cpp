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
    //solution 1: Recursive solution
    void reverse(ListNode* s,ListNode* e){
        ListNode *p = NULL,*c = s,*n=s->next;
        while(p!=e){
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL)n=n->next;
        }
    }
    
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head == NULL || head->next == NULL || k==1) return head;
        ListNode *s = head, *e = head;
        int inc = k-1;
        while(inc--){
            e = e->next;
            if(e == NULL) return head;
        }
        
        ListNode* nextHead = reverseKGroup(e->next,k); //recursive call
        reverse(s,e);
        s->next = nextHead;
        return e;
    }
    */
    
    
    //solution 2: O(1) space solution .. interview follow up.. iterative solution
    void reverse(ListNode* s,ListNode* e){
        ListNode *p = NULL,*c = s,*n=s->next;
        while(p!=e){
            c->next = p;
            p = c;
            c = n;
            if(n!=NULL)n=n->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head == NULL || head->next == NULL || k==1) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next=head;
        ListNode *beforeStart = dummy, *e = head;
        int i = 0;
        while(e!=NULL){
            i++;
            if(i%k == 0){
                //reversal
                ListNode *s = beforeStart->next, *temp = e->next;
                reverse(s,e);
                beforeStart->next = e;
                s->next = temp;
                beforeStart = s;
                e = temp;
            }
            else{
                e = e->next;
            }
        }
        return dummy->next;
    }
};