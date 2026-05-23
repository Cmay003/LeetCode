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
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL || head==NULL) return head;
        ListNode* first=head;
        ListNode* second=first->next;
        while(second!=NULL){
            int val1= first->val;
            int val2= second->val;
            ListNode* temp = new ListNode(gcd(val1, val2));
            temp->next=second;
            first->next=temp;
            first=second;
            second=second->next;
        }
        return head;
    }
};