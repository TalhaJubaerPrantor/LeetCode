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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        int isLooped=0;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                isLooped=1;
            }
            if(isLooped){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        }

        
        return NULL;
    }
};