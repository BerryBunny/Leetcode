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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {

     int total=0;
     int next1=0;
     ListNode *result=new ListNode(0);
     ListNode *cur =result;

     while(l1 and l2)
     {
         total=l1->val+l2->val+next1;
         next1=(total)/10;
         cur->next=new ListNode (total%10);
         l1=l1->next;
         l2=l2->next;
         cur=cur->next;
     }

     while(l1)
     {
         total=l1->val+next1;
         next1=(total)/10;
         cur->next=new ListNode ((total)%10);
         l1=l1->next;
         cur=cur->next;
     }

     while(l2)
     {
         total=l2->val+next1;
         next1=(total)/10;
         cur->next=new ListNode ((total)%10);
         l2=l2->next;
         cur=cur->next;
     }

     if(next1)
     {
         cur->next=new ListNode (next1);
     }

     return result->next;
    }
};
