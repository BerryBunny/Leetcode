//iterative
//Time O(N)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       if(l1==nullptr) return l2;
       if(l2==nullptr) return l1;
       ListNode *dummy = new ListNode(0);
       ListNode *result= dummy;
       while(l1 and l2)
       {
           if(l1->val < l2->val)
           {
               result->next=l1;
               l1=l1->next;
           }
           else
           {
               result->next=l2;
               l2=l2->next;
           }
           result=result->next;
       }
       result->next=l1? l1:l2;
       return dummy->next;
    }
};
