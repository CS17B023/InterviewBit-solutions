/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) 
{
    if(A == NULL || A->next == NULL)
        return A;
    
    
    ListNode* temp1 = NULL;
    ListNode* temp2 = NULL;
    ListNode* l1 = temp1;
    ListNode* l2 = temp2;
    
    ListNode* temp = A;
    
    while(temp != NULL)
    {
        if(temp->val < B)
        {
            if(temp1 == NULL)
            {
                temp1 = new ListNode(temp->val);
                l1 = temp1;
            }
            else
            {
                l1->next = new ListNode(temp->val);
                l1 = l1->next;
            }
        }
        else
        {
            if(temp2 == NULL)
            {
                temp2 = new ListNode(temp->val);
                l2 = temp2;
            }
            else
            {
                l2->next = new ListNode(temp->val);
                l2 = l2->next;
            }
        }
        
        ListNode* kuku = temp;
        temp = temp->next;
        kuku = NULL;
        A = temp;
    }
    
    if(temp1 == NULL)
        return temp2;
    l1->next = temp2;
    return temp1;
}
