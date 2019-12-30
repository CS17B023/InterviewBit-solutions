/*Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) 
{
    if(A == NULL || A->next == NULL)
        return 1;
        
    ListNode* slow = A;
    ListNode* fast = A;
    ListNode* prev_of_slow = A;
    
   
    while(fast != NULL && fast->next != NULL)
    {
        prev_of_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast != NULL)
        slow = slow->next;
    
    
    ListNode* second_half = slow;
    prev_of_slow->next = NULL;
    
   
    
    ListNode* current = slow;
    ListNode* prev = NULL;
    ListNode* nex = NULL;
    
    while(current != NULL)
    {
        nex = current->next;
        current->next = prev;
        prev = current;
        current = nex;
    }
     second_half  = prev;
    
    ListNode* temp1 = A;
    ListNode* temp2 = second_half;
    
    while(temp1 && temp2)
    {
        if(temp1->val == temp2-> val)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }
    if(temp1 == NULL && temp2 == NULL)
        return 1;
    else
        return 0;
}
