/*Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
  ListNode* rev(ListNode *A){
      ListNode *prev=NULL;
    ListNode *curr=A;
    ListNode *next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
 }
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) 
{
    if(A == NULL || A->next == NULL)
        return A;
        
    int len = 0;
    ListNode* tempu = A;
    
    while(tempu != NULL)
    {
        len++;
        tempu = tempu->next;
    }
    
    if(B > len || C > len)
        return A;
    if(B < 1 || C < 1)
        return A;
        
        
     if(B == C)
        return A;
    ListNode *temp = A,*first = A,*last = A,*prev=NULL;
    int i=1;
    for(;i<B;i++)
    {
     prev=temp;
     temp=temp->next;
    }
   
   first=temp;
   
    for(;i<C;i++)
     temp=temp->next;
    last=temp;
    
    ListNode* next=last->next;
    last->next=NULL;
    
    first = rev(first);
    
    if(prev!=NULL)prev->next=first;
    else A=first;
    temp=first;
    while(temp->next!=NULL)
     temp=temp->next;
    
    temp->next=next;
    return A;
}
