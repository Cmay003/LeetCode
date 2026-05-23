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
    ListNode* reverse(ListNode* head){
        if(head==NULL) return NULL;
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* last=temp->next;
        while(temp!=NULL){
            last=temp->next;
            temp->next=prev;
            prev=temp;
            temp=last;
        }
        head=prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* temp=reverse(slow);
        ListNode* h1=head;
        while(temp!=NULL){
            if(h1->val!=temp->val) return false;
            h1=h1->next;
            temp=temp->next;
        }
        return true;
    }
};