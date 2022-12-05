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
        //iterative solution
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        temp = head;
        n = n/2;
        while(n--){
            temp = temp->next;
        }
        return temp;
    }
};