// O(n)
class Solution {
    void swap(ListNode* prev)
    {
        ListNode *dummy = prev->next;
        prev->next=dummy->next;
        dummy->next=dummy->next->next;
        prev->next->next=dummy;
    }
public:
    ListNode* swapPairs(ListNode* head)
    {
      ListNode *dummy=new ListNode(0);
      dummy->next=head;
      ListNode* cur=dummy;
      while(cur and cur->next and cur->next->next)
      {
          swap(cur);
          cur=cur->next->next;
      }
        return dummy->next;
    }
};



class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
      ListNode *dummy=new ListNode(0);
      dummy->next=head;
      ListNode* cur=dummy;
      while(cur and cur->next and cur->next->next)
      {
          ListNode* First=cur->next;
          ListNode* Second=First->next;
          cur->next=Second;
          First->next=First->next->next;
          cur->next->next=First;
          cur=cur->next->next;
      }
        return dummy->next;
    }
};
