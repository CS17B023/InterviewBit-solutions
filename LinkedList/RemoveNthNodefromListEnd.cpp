/*Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) 
{
    if(A == NULL) 
        return NULL;
    if(A->next == NULL && B == 1) 
        return NULL;
    
    ListNode* temp = A;
    int len = 0;
    
    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    
     
    if(len <= B)
    {
        
         A = A->next;
        
        return A;
    }
    
    
    len = len - B;
    
    // if(len < 0) 
    //     return A;
   
    
    
    temp = A;
    int count = 1;
    while(count < len && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    
    ListNode* tmp = temp->next;
    temp->next = tmp->next;
    tmp = NULL;
    return A;
    
}
