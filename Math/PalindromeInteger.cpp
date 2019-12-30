/*Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False*/


int Solution::isPalindrome(int A) 
{
    int temp = A;
    int sum = 0;
    
    
    while(A > 0)
    {
        int rem = A%10;
        sum = sum*10 + rem;
        A = A/10;
    }
    if(temp-sum == 0)
        return 1;
    else
        return 0;
}
