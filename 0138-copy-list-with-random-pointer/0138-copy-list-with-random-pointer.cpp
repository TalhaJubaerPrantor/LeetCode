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
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        
        Node* newHead= new Node(head->val);
        Node* newTemp=newHead;
        Node* oldTemp=head;

        unordered_map<Node*, Node*> m;

        while(oldTemp!=NULL){
            Node* copy=new Node(oldTemp->val);
            m[oldTemp]=copy;
            newTemp->next=copy;
            newTemp=newTemp->next;
            oldTemp=oldTemp->next;
        }
    
        oldTemp=head;
        newTemp=newHead->next;
        while(oldTemp!=NULL){
            if(oldTemp->random!=NULL){
                newTemp->random=m[oldTemp->random];
            }
            oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }
        return newHead->next;
    }
};