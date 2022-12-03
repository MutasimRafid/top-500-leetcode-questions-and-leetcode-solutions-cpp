/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //solution 1: with extra space
    //TC: O(n) .... SC:O(n)
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> m; //[key,value] = [previous list's address, New list's address]
        Node* temp = head;
        while(temp!=NULL){
            Node* copy = new Node(temp->val);
            m[temp] = copy; //copy is a pointer also(Node type) ..storing current new node's address
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }
        return m[head];
    }
};