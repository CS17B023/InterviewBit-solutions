/*Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A)
{
    
    if(A == NULL || A->next == NULL) 
        return A;
        
    
    ListNode* temp1 = A;
    ListNode* temp2 = A->next;
    ListNode* temp  = A->next;
    ListNode* kuku = temp1;
    
    while(temp2 != NULL)
    {
        if(temp2->val != temp1->val)
        {
            kuku = temp;
            temp1 = temp2;
            temp->val = temp2->val;
            temp  = temp->next;
            temp2 = temp2->next; 
        }
        else
            temp2 = temp2->next;
        
    }
    
    kuku->next = NULL;
        
    
    
    return A;
}
