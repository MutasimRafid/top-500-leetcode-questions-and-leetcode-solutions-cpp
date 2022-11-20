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
//solution 1: use normal vector
//solution 2: use loop
//solution 3: use heap
class cmp{
    public:
    bool operator()(ListNode *a,ListNode *b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //priority queue will always store k smallest elements from k sorted lists
        priority_queue<ListNode*, vector<ListNode*>, cmp>q;
        
        //firstly, we all enter all the k nodes into our Min-Heap
        for(int i = 0;i<lists.size();i++){
            if(lists[i]!=NULL){
                q.push(lists[i]);
            }
        }
        
        //dummy pointer that will point to head
        ListNode *dummy = new ListNode(-1);
        //tail pointer that will help us to add nodes into our k merged sorted Linked list
        ListNode *tail = dummy;
        
        //till q has nodes
        while(q.size()){
            ListNode *temp = q.top();
            q.pop();
            
            tail->next = temp;
            tail = tail->next;
            
            //we enter temp's next node into our priority queue
            if(temp->next != NULL){
                q.push(temp->next);
            }
        }
        return dummy->next;
    }
};