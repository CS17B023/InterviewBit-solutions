/*Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) 
{
    if(B == 0)
        return A;
    if(A == NULL || A->next == NULL) 
        return A;
        
        
    ListNode* temp = A;
    ListNode* last;
    ListNode* head = A;
    
    int len = 0;
    
    
    while(temp != NULL)
    {
        last = temp;
        temp = temp->next;
        len++;
    }
    
    while(B >= len)
        B = B - len;
    
    
    B = len - B;
    
    last->next = head;
    temp = A;
    
    while(B--)
    {
        last = temp;
        temp = temp->next;
    }
    head = temp;
    last->next = NULL;
    
    return head;
    
}
