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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        int cnt=1;
        while(temp->next->next!=NULL){
            temp=temp->next;
            cnt++;
        }
        cnt++;
         if(cnt==k){
            return head;
        }
        temp->next->next=head;
        
        
       
        int idx=0;
        if(k>cnt){
            idx=cnt-(k%cnt);
        }else{
            idx=cnt-k;
        }
        //cout<<idx;
        cnt=1;
        temp=head;

        while(cnt<idx){
            temp=temp->next;
            cnt++;
        }
        ListNode* last=temp;
        temp=temp->next; 
        last->next=NULL;
        //temp->next=head;

        return temp;
    }
};


