/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* rever(ListNode* head)
{
    ListNode* current = head;
    ListNode* prev = NULL;
    ListNode* nex = NULL;
    while(current != NULL)
    {
        nex = current->next;
        current->next = prev;
        
        prev = current;
        current = nex; 
    }
    head = prev;
    
    return head;
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B)
{
    ListNode* res = NULL;
    
    int m = 0;
    int n = 0;
    ListNode* head1 = A;
    ListNode* head2 = B;
    ListNode* temp = NULL;
    
    while(head1 != NULL)
    {
        m++;
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        n++;
        head2 = head2->next;
    }
    head1 = rever(A);
    head2 = rever(B);
    int carry = 0;
    
    if(m <= n)
    {
        for(int i = 0; i < m; i++)
        {
            int sum = head1->val + head2->val + carry;
            int data = sum%10;
            if(temp == NULL)
            {
                 temp = new ListNode(data);   
                 res = temp;
            }
            else
            {
                 res->next = new ListNode(data);
                 res = res->next;
            }
               
            carry = sum/10; 
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head2 != NULL)
        {
            int sum = head2->val + carry;
            int data = sum%10;
            
            res->next = new ListNode(data);
            res = res->next;
            
            carry = sum/10;
            head2 = head2->next;
        }
        if(carry)
        {
            res->next = new ListNode(carry);
            res = res->next;
        }
             
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            int sum = head1->val + head2->val + carry;
            int data = sum%10;
            if(temp == NULL)
            {
                 temp = new ListNode(data);   
                 res = temp;
            }
            else
            {
                 res->next = new ListNode(data);
                 res = res->next;
            }
               
            carry = sum/10; 
            head1 = head1->next;
            head2 = head2->next;
        }
        while(head1 != NULL)
        {
            int sum = head1->val + carry;
            int data = sum%10;
            
            res->next = new ListNode(data);
            res = res->next;
            
            carry = sum/10;
            head1 = head1->next;
        }
        if(carry)
        {
            res->next = new ListNode(carry);
            res = res->next;
        }
    }
    return temp;
}
