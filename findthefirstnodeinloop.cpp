class Solution {
  public:
    Node* findFirstNode(Node* head) {
        // your code here
       Node *slow=head;
       Node *fast=head;
       while(fast!=NULL && fast->next!=NULL)
       {
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast)
           {
               slow=head;
               while(slow!=fast)
               {
                   slow=slow->next;
           fast=fast->next;
               }
               return slow;
           }
           
       }
       return NULL;
    }
};
