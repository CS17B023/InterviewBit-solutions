/*Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A)
{
    if(A == NULL || A->next == NULL)
        return A;
    ListNode* temp1 = A;
    ListNode* temp2 = A->next;
    
    while(temp2 != NULL && temp2->next != NULL)
    {
        int temp = temp1->val;
        temp1->val = temp2->val;
        temp2->val = temp;
        
        temp1 = temp1->next->next;
        temp2 = temp2->next->next;
    }
    return A;
}
