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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
         ListNode* temp;
        while(curr!=NULL)
        {
             temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r1=reverse(l1);
        ListNode *r2=reverse(l2);
          ListNode* temp=new ListNode();
ListNode* head=temp;
int carry=0;
        while(r1 || r2 || carry)
        {
       
            int sum=carry;
            if(r1) sum+=r1->val, r1=r1->next;
           
            if(r2) sum+=r2->val, r2=r2->next;    
           carry=sum/10;
           head->next=new ListNode(sum%10);
           head=head->next;
        }
        temp=reverse(temp->next);
        return temp;
    }
};
