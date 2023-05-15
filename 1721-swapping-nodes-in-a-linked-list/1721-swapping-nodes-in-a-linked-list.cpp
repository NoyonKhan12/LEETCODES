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
    
    // int length(ListNode* head)
    // {
    //     int count = 0 ;
    //     while(head != nullptr)
    //     {
    //         head = head->next;
    //         count++;
    //     }
    //     return count;
    // }
    
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* curr = head;

        // Traverse the linked list until the kth node from the beginning
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }
        first = curr;

        // Traverse the linked list from the kth node until the end
        while (curr->next != NULL) {
            curr = curr->next;
            second = second->next;
        }

        // Swap the values of the two nodes
        int temp = first->val;
        first->val = second->val;
        second->val = temp;

        return head;
    }
};