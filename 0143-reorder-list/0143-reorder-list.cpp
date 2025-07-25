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
private:
ListNode *reverse(ListNode* head){
    ListNode*prev=NULL;
    ListNode*next;
    ListNode*temp=head;
    while(temp!=NULL){
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *newhead=reverse(slow->next);
        slow->next=NULL;
        ListNode*first=head;
        ListNode*sec=newhead;
        //merge the halves
        //check for sec!=NULL , since the 2nd 1/2 can be shorter than the 1st 1/2
        while( sec!=NULL){
            ListNode*temp1=first->next;
            ListNode*temp2=sec->next;
            first->next=sec;
            //connect the ll's here
            sec->next=temp1;
            first=temp1;
            sec=temp2;
        }
    }
};