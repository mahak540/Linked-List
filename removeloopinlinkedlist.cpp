class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
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
             while(fast->next!=slow)
             {
                 fast=fast->next;
             }
             fast->next=NULL;
             return ;
            }
        }
        
    }
};
