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
    //most optimized approach
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode* temp = head;
        while(temp != NULL){
            ans *= 2;
            ans += temp->val; //2^0 = 1.. so 1* anyNumber = anyNumber. so ignored
            temp = temp->next;
        }
        return ans;
    }
};