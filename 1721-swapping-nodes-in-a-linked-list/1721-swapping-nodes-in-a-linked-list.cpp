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
    
    int length(ListNode* head)
    {
        int count = 0 ;
        while(head != nullptr)
        {
            head = head->next;
            count++;
        }
        return count;
    }
    
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* n1 = head;
        ListNode* n2 = head;

        int n = length(head);
        int i = 1 ;

        while(i < k)
        {
            n1 = n1->next;
            i++;
        }
        
        i = 1;
        
        while(i <= n-k)
        {
            n2 = n2->next;
            i++;
        }
        
        swap(n1->val, n2->val);

        return head;
    }
};