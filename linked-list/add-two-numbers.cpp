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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1=l1;
        ListNode* num2=l2;
        ListNode* ans= new ListNode(-1);
        ListNode* prev=ans;
        int carry=0;
        while(num1!=NULL || num2!=NULL){
            int sum=carry;
            if(num1){ 
                sum+=num1->val;
                num1=num1->next;
            }
            if(num2){ 
                sum+=num2->val;
                num2=num2->next;
            }
            ListNode* newNode= new ListNode(sum%10);
            carry=sum/10;
            prev->next=newNode;
            prev=prev->next;
        }
        if(carry){
            ListNode* newNode= new ListNode(carry);
            prev->next=newNode;
        }
        return ans->next;
    }
};