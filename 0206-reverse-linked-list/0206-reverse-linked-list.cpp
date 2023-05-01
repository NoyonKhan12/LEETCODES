class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    { 
        if(head == NULL)
        {
            return head;
        }
        
        ListNode *previous = NULL, *current = head, *later = head->next;
        
        while(current != NULL)
        {
            current->next = previous;
            previous = current;
            current = later;
            
            if(later != NULL)
            {
                later = later->next;
            }
        }
        return previous;
    }
};