class Solution {
  public:
    int getKthFromLast(Node *head, int k) {
        // Your code here
        Node *slow=head;
        Node *fast=head;
        
        for(int i=1;i<k;i++)
        {
            fast=fast->next;
            if(fast==NULL)
            return -1;
            
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow->data;
    }
};
